
namespace pointers {
 
	template<class Type>
	class UniquePTR
	{
	private:
		Type* ptr;
	public:
		UniquePTR();
		UniquePTR(Type*);
		~UniquePTR();

		Type* get();
		void swap(UniquePTR<Type>&);// it's the one way to swap pointers between objects
		void reset();
		void release();
		Type& operator*();
		Type& operator->();

		UniquePTR(UniquePTR<Type>&) = delete;
		void operator=(const UniquePTR<Type>&) = delete;

	};

	template<class Type>
	class UniquePTR<Type[]>
	{
	private:
		Type* ptr;
		size_t sizeOfArray;
	public:
		UniquePTR();
		UniquePTR(Type*, size_t);
		~UniquePTR();

		Type* getPointer();
		size_t getSizeOfArray();
		void swap(UniquePTR<Type[]>&);
		void reset();
		void release();
		Type& operator[](long long);

		UniquePTR(UniquePTR<Type[]>&) = delete;
		void operator=(const UniquePTR<Type[]>&) = delete;

	};

	// definition of "Type" template

	template<class Type>
	UniquePTR<Type>::UniquePTR() :ptr(nullptr) {

	}

	template<class Type>
	UniquePTR<Type>::UniquePTR(Type* outsidePointer) {
		this->ptr = outsidePointer;
	}

	template<class Type>
	UniquePTR<Type>::~UniquePTR() {
		delete this->ptr;
	}

	template<class Type>
	Type* UniquePTR<Type>::get() {

		return this->ptr;
	}

	template<class Type>
	void UniquePTR<Type>::swap(UniquePTR<Type>& outObject) {
		Type* temporary = this->ptr;
		this->ptr = outObject.ptr;
		outObject.ptr = temporary;
	}

	template<class Type>
	void UniquePTR<Type>::reset() {
		delete this->ptr;
		this->ptr = nullptr;
	}


	template<class Type>
	void UniquePTR<Type>::release() {
		this->ptr = nullptr;
	}
	
	template<class Type>
	Type& UniquePTR<Type>::operator*() {
			return this->ptr;
	}

	template<class Type>
	Type& UniquePTR<Type>::operator->() {
		return this->ptr;
	}

	// definition of "Type[]" template

	template<class Type>
	UniquePTR<Type[]>::UniquePTR() :ptr(nullptr), sizeOfArray(0) {

	}

	template<class Type>
	UniquePTR<Type[]>::UniquePTR(Type* outsidePointer, size_t length) {
		this->ptr = outsidePointer;
		this->sizeOfArray = length;
	}

	template<class Type>
	UniquePTR<Type[]>::~UniquePTR() {
		delete this->ptr;
		this->sizeOfArray = 0;
	}

	template<class Type>
	Type* UniquePTR<Type[]>::getPointer() {

		return this->ptr;
	}


	template<class Type>
	size_t UniquePTR<Type[]>::getSizeOfArray()  {
		return this->sizeOfArray;
	}



	template<class Type>
	void UniquePTR<Type[]>::swap(UniquePTR<Type[]>& outObject) {
		Type* temporaryPointerOfthisObject = this->ptr;
		this->ptr = outObject.ptr;
		outObject.ptr = temporaryPointerOfthisObject;
		size_t temporarySizeOfthisObject = this->sizeOfArray;
		this->sizeOfArray = outObject.sizeOfArray;
		outObject.sizeOfArray = temporarySizeOfthisObject;
	}

	template<class Type>
	void UniquePTR<Type[]>::reset() {
		delete this->ptr;
		this->ptr = nullptr;
		this->sizeOfArray = 0;
	}


	template<class Type>
	void UniquePTR<Type[]>::release() {
		this->ptr = nullptr;
		this->sizeOfArray = 0;
	}

	template<class Type>
	Type& UniquePTR<Type[]>::operator[](long long indexOfArray) {
		return this->ptr[indexOfArray];
	}
	
}



