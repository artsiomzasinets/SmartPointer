
namespace pointers {

	template<class Type>
	class sharedPtr {
	private:

		class Indexer {
		public:
			size_t amountOfpointers;
			
			Indexer() :amountOfpointers(1) {

			}

			void increaseForOne() {
				++amountOfpointers;
			}
			
		};

		void transfer(sharedPtr& outObj) { //increase counter of reference.

			ptr = outObj.ptr;
			leader = outObj.leader;
			if (leader != nullptr) {
				leader->increaseForOne();
			}
		}

		void checkToFree() { // check counter of reference for deleting

			if (ptr != nullptr && leader != nullptr)
			{
				if (leader->amountOfpointers > 1) {
					leader->amountOfpointers--;
				}
				else
				{
					delete leader;
					delete ptr;
				}
			}

		}

		Indexer* leader;
		Type* ptr;
	public:

		sharedPtr():ptr(nullptr),leader(nullptr) {

		}

		sharedPtr(Type* outType) {
			ptr = outType;
			leader = new Indexer;
		}

		sharedPtr(sharedPtr& outObj) {
			transfer(outObj);
		}

		sharedPtr& operator=(sharedPtr& outObj) {
			checkToFree();
			transfer(outObj);
			return *this;
		}

		void swap(sharedPtr& outObj) { // swap smartPointers 
			Type* tempType = ptr;
			Indexer* tempIndexer = leader;
			ptr = outObj.ptr;
			leader = outObj.leader;
			outObj.ptr = tempType;
			outObj.leader = tempIndexer;
		}

		void reset(Type * newPtr) { // reset the pointer to new one

			checkToFree();
			ptr = newPtr;
			leader = new Indexer;
		}

		Type* get() {
			return ptr;
		}

		Type& operator*() {
			if (ptr != nullptr)
				return *ptr;
		}

		Type* operator->() {
			
			return ptr;
		}

		bool unique() {
			if (ptr != nullptr && leader != nullptr) {
				return leader->amountOfpointers == 1 ? true : false;
			}
			else
			{
				return true;
			}
				
		}
		
		size_t use_count() {
			if (ptr != nullptr && leader != nullptr)
			{
				return leader->amountOfpointers;
			}
			else
			{
				return 0;
			}
		
		}


		~sharedPtr() {
			checkToFree();
		}
	};

}