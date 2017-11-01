#include "MyString.h"
#include <iostream>

int main()
{
	MyString * some_str = new MyString();
	std::cout << "Trying to print an empty string" << std::endl;
	std::cout << some_str->GetStringPtr() << std::endl;

	MyString * some_str_2 = new MyString("This is a test!");
	std::cout << "Trying to print a Mystrig test created be a c-string string" << std::endl;
	std::cout << some_str_2->GetStringPtr() << std::endl;

	MyString * some_str_3 = new MyString("This is a test!");
	std::cout << "Trying to print a Mystrig test created by a copy of a MyString" << std::endl;
	std::cout << some_str_3->GetStringPtr() << std::endl;

	std::cout << "Testing Assign" << std::endl;
	some_str_3->Assign(new MyString("This a new string"));
	std::cout << some_str_3->GetStringPtr() << std::endl;

	std::cout << "Testing Append" << std::endl;
	some_str_3->Append(some_str_2);
	std::cout << some_str_3->GetStringPtr() << std::endl;

	std::cout << "Testing IsEmpty" << std::endl;
	std::cout << some_str->IsEmpty() << std::endl;
	std::cout << some_str_3->IsEmpty() << std::endl;

	std::cout << "Testing GetLenth" << std::endl;
	std::cout << some_str->GetLength() << std::endl;
	std::cout << some_str_3->GetLength() << std::endl;

	std::cout << "Testing Compare" << std::endl;
	std::cout << some_str->Compare(some_str_2) << std::endl;
	std::cout << some_str_3->Compare(some_str_2) << std::endl;

	std::cout << "Testing CharAt" << std::endl;
	std::cout << some_str_2->CharAt(0) << std::endl;
	std::cout << some_str_3->CharAt(1) << std::endl;

	std::cout << "Testing Clear" << std::endl;
	some_str_2->Clear();
	std::cout << some_str_2->IsEmpty() << std::endl;


	delete some_str;
	delete some_str_2;
	delete some_str_3;
	return 0;
}