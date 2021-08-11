#include<iostream>
#include<memory>

#include "UniquePTR.cpp"
#include "sharedPtr.cpp"

using namespace pointers;



int main() {

	try
	{	
		
		sharedPtr<int> obj1;
		sharedPtr<int> obj3(new int(118));
		obj1.swap(obj3);
		std::cout << *obj1;
		{
			sharedPtr<int> obj4(obj3);
		}
		sharedPtr<int> obj2(obj1);
		
	}
	catch (const std::exception& err)
	{
		err.what();
	}


	return 0;
}