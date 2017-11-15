#include "MyString.h"
#include <iostream>

using namespace yik;

int main()
{
	String some_str;
	std::cout << "Trying to print an empty string" << std::endl;
	std::cout << some_str << std::endl;

	String some_str_2("This is a test!");
	std::cout << "Trying to print a Mystrig test created be a c-string string" << std::endl;
	std::cout << some_str_2 << std::endl;

	String some_str_3("This is a test!");
	std::cout << "Trying to print a Mystrig test created by a copy of a String" << std::endl;
	std::cout << some_str_3 << std::endl;


	std::cout << "Testing Assign with String" << std::endl;
	some_str_3.Assign(String("This a new String"));
	std::cout << some_str_3 << std::endl;

	std::cout << "Testing Assign with c_string" << std::endl;
	some_str_3.Assign(String("This a new c_string"));
	std::cout << some_str_3 << std::endl;


	std::cout << "Testing Append with String" << std::endl;
	some_str_3.Append(some_str_2);
	std::cout << some_str_3 << std::endl;

	std::cout << "Testing Append with c_string" << std::endl;
	some_str_3.Append("Appending a c_string");
	std::cout << some_str_3 << std::endl;


	std::cout << "Testing IsEmpty" << std::endl;
	std::cout << some_str.IsEmpty() << std::endl;
	std::cout << some_str_3.IsEmpty() << std::endl;

	std::cout << "Testing GetLenth" << std::endl;
	std::cout << some_str.GetLength() << std::endl;
	std::cout << some_str_3.GetLength() << std::endl;

	std::cout << "Testing Compare String" << std::endl;
	std::cout << some_str.Compare(some_str_2) << std::endl;
	std::cout << some_str_3.Compare(some_str_2) << std::endl;

	std::cout << "Testing Compare c_string" << std::endl;
	std::cout << some_str.Compare("asdfasdasdkfjhaskldjfhlkasdflkahsdlfkjhaskjdfhlaksjdhflkashdflkajshdfasdf") << std::endl;
	std::cout << some_str_3.Compare("as") << std::endl;

	std::cout << "Testing Compare oprators == " << std::endl;
	std::cout << (some_str == some_str_2) << std::endl;
	std::cout << (some_str_3 == some_str_2) << std::endl;

	std::cout << "Testing Compare oprators != " << std::endl;
	std::cout << (some_str != some_str_2) << std::endl;
	std::cout << (some_str_3 != some_str_2) << std::endl;

	std::cout << "Testing Compare oprators < " << std::endl;
	std::cout << (some_str < some_str_2) << std::endl;
	std::cout << (some_str_3 < some_str_2) << std::endl;

	std::cout << "Testing Compare oprators <= " << std::endl;
	std::cout << (some_str <= some_str_2) << std::endl;
	std::cout << (some_str_3 <= some_str_2) << std::endl;

	std::cout << "Testing Compare oprators > " << std::endl;
	std::cout << (some_str > some_str_2) << std::endl;
	std::cout << (some_str_3 > some_str_2) << std::endl;

	std::cout << "Testing Compare oprators >= " << std::endl;
	std::cout << (some_str >= some_str_2) << std::endl;
	std::cout << (some_str_3 >= some_str_2) << std::endl;

	std::cout << "Testing CharAt" << std::endl;
	std::cout << some_str_2.CharAt(0) << std::endl;
	std::cout << some_str_3.CharAt(1) << std::endl;

	std::cout << "Testing Clear" << std::endl;
	some_str_2.Clear();
	std::cout << some_str_2.IsEmpty() << std::endl;

	system("Pause");

	return 0;
}