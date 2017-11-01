#include "MyString.h"
#include <iostream>

int main()
{
	MyString some_str;
	std::cout << "Trying to print an empty string" << std::endl;
	std::cout << some_str.c_str() << std::endl;

	MyString some_str_2("This is a test!");
	std::cout << "Trying to print a Mystrig test created be a c-string string" << std::endl;
	std::cout << some_str_2.c_str() << std::endl;

	MyString some_str_3("This is a test!");
	std::cout << "Trying to print a Mystrig test created by a copy of a MyString" << std::endl;
	std::cout << some_str_3.c_str() << std::endl;

	const char * test = some_str_3.c_str();

	std::cout << "Testing Assign with MyString" << std::endl;
	some_str_3.Assign(MyString("This a new MyString"));
	std::cout << some_str_3.c_str() << std::endl;

	std::cout << "Testing Assign with c_string" << std::endl;
	some_str_3.Assign(MyString("This a new c_string"));
	std::cout << some_str_3.c_str() << std::endl;


	std::cout << "Testing Append with MyString" << std::endl;
	some_str_3.Append(some_str_2);
	std::cout << some_str_3.c_str() << std::endl;

	std::cout << "Testing Append with c_string" << std::endl;
	some_str_3.Append("Appending a c_string");
	std::cout << some_str_3.c_str() << std::endl;


	std::cout << "Testing IsEmpty" << std::endl;
	std::cout << some_str.IsEmpty() << std::endl;
	std::cout << some_str_3.IsEmpty() << std::endl;

	std::cout << "Testing GetLenth" << std::endl;
	std::cout << some_str.GetLength() << std::endl;
	std::cout << some_str_3.GetLength() << std::endl;

	std::cout << "Testing Compare MyString" << std::endl;
	std::cout << some_str.Compare(some_str_2) << std::endl;
	std::cout << some_str_3.Compare(some_str_2) << std::endl;

	std::cout << "Testing Compare c_string" << std::endl;
	std::cout << some_str.Compare("asdfasdasdkfjhaskldjfhlkasdflkahsdlfkjhaskjdfhlaksjdhflkashdflkajshdfasdf") << std::endl;
	std::cout << some_str_3.Compare("as") << std::endl;


	std::cout << "Testing CharAt" << std::endl;
	std::cout << some_str_2.CharAt(0) << std::endl;
	std::cout << some_str_3.CharAt(1) << std::endl;

	std::cout << "Testing Clear" << std::endl;
	some_str_2.Clear();
	std::cout << some_str_2.IsEmpty() << std::endl;

	return 0;
}