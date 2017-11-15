#include "MyString.h"
#include <cstring>
#include <limits>

#pragma region CTOR/DTOR

yik::String::String() : str_ptr(nullptr) , str_size(0)
{
	str_ptr = new char[1];
	str_ptr[str_size] = 0x0;
}

yik::String::String(String & my_string) : str_ptr(nullptr), str_size(0)
{
	Assign(my_string);
}

yik::String::String(const char * str) : str_ptr(nullptr), str_size(0)
{
	size_t str_len = std::strlen(str);
	
	//case the string is bigger than the size that it can be allocated, the string is not created
	if (str_len == SIZE_MAX - 1)
	{
		return;
	}

	this->str_size = str_len;
	this->str_ptr = new char[this->str_size + 1];

	strncpy(this->str_ptr, str, str_len);
	this->str_ptr[this->str_size] = 0x0;

}

yik::String::~String()
{
	if (str_ptr)
		delete [] str_ptr;
}

#pragma endregion

#pragma region Functions

size_t yik::String::GetLength() const
{
	return str_size;
}

void yik::String::Assign(const String & my_string)
{
	Clear();

	//Don't need to check the other String, we use the assumption all the values are valid
	this->str_size = my_string.GetLength();
	this->str_ptr = new char[this->str_size + 1];
	strncpy(this->str_ptr, my_string.c_str(), this->str_size);
	this->str_ptr[this->str_size] = 0x0;

}

void yik::String::Assign(const char * c_str)
{
	Clear();
	str_size = strlen(c_str);
	str_ptr = new char[str_size + 1];
	strncpy(str_ptr, c_str, str_size);
	str_ptr[str_size] = 0x0;
}

//get integer at the n-th position
// throw an exeption if index is out of boundries
char yik::String::CharAt(const unsigned int index) const
{
	if (index >= str_size)
		throw("Index out of boundries");

	return str_ptr[index];
}

//append another string to this string
// return true is manage to do it
bool yik::String::Append(const yik::String & my_string)
{
	//check if can be appended
	if (my_string.GetLength() > SIZE_MAX - this->str_size)
	{
		return false;
	}

	size_t new_str_size = my_string.GetLength() + this->str_size;

	if (new_str_size == SIZE_MAX - 1)
	{
		return false;
	}

	//copy new string to new_str_ptr
	char * new_str_ptr = new char[new_str_size + 1];
	strncpy(new_str_ptr, this->str_ptr, this->str_size);
	new_str_ptr[this->str_size] = 0x0;
	strncat(new_str_ptr, my_string.c_str(), my_string.GetLength());
	new_str_ptr[new_str_size] = 0x0;

	//remove and change ptr
	Clear();
	this->str_ptr = new_str_ptr;
	this->str_size = new_str_size;

	return true;
}

bool yik::String::Append(const char * c_str)
{
	const size_t c_str_size = strlen(c_str);

	//check if can be appended
	if (c_str_size > SIZE_MAX - this->str_size)
	{
		return false;
	}

	size_t new_str_size = c_str_size + this->str_size;

	if (new_str_size == SIZE_MAX - 1)
	{
		return false;
	}

	//copy new string to new_str_ptr
	char * new_str_ptr = new char[new_str_size + 1];
	strncpy(new_str_ptr, this->str_ptr, this->str_size);
	new_str_ptr[this->str_size] = 0x0;
	strncat(new_str_ptr, c_str, c_str_size);
	new_str_ptr[new_str_size] = 0x0;

	//remove and change ptr
	Clear();
	this->str_ptr = new_str_ptr;
	this->str_size = new_str_size;

	return true;
}

//Compare this with another string
//Returns an integral value indicating the relationship between the strings :
// +--------------+--------------------------------------------------------------------------------------------------+
// | return value | indicates																						 |
// +--------------+--------------------------------------------------------------------------------------------------+
// |	 <0		  | the first character that does not match has a lower value in this than in my_string				 |
// +--------------+--------------------------------------------------------------------------------------------------+
// |      0		  |	the contents of both strings are equal															 |
// +--------------+--------------------------------------------------------------------------------------------------+
// |	 >0		  |	the first character that does not match has a greater value in this than in my_string			 |
// +--------------+--------------------------------------------------------------------------------------------------+
int yik::String::Compare(const String & my_string) const
{
	return strcmp(this->c_str(), my_string.c_str());
}

//Compare this with another c_string
//Returns an integral value indicating the relationship between the c_strings :
// +--------------+--------------------------------------------------------------------------------------------------+
// | return value | indicates																						 |
// +--------------+--------------------------------------------------------------------------------------------------+
// |	 <0		  | the first character that does not match has a lower value in this than in c_string				 |
// +--------------+--------------------------------------------------------------------------------------------------+
// |      0		  |	the contents of both strings are equal															 |
// +--------------+--------------------------------------------------------------------------------------------------+
// |	 >0		  |	the first character that does not match has a greater value in this than in c_string			 |
// +--------------+--------------------------------------------------------------------------------------------------+
int yik::String::Compare(const char * c_string) const
{
	return strcmp(this->c_str(), c_string);
}

//Return is the string is empty
bool yik::String::IsEmpty() const
{
	return (str_size == 0);
}

//Clear the string
void yik::String::Clear()
{
	if (!str_size)
	{
		delete str_ptr;

		str_ptr = new char[1];
		str_ptr[str_size] = 0x0;
		str_size = 0;
	}

}

//Return a Read Only reference to the string
const char * yik::String::c_str() const
{
	{ return str_ptr; }
}

#pragma endregion

#pragma region Operators

yik::String & yik::String::operator=(const String & my_str)
{
	Assign(my_str);
	return *this;
}

yik::String & yik::String::operator=(const char * my_str)
{
	Assign(my_str);
	return *this;
}

//compare two Strings
bool yik::String::operator==(const String & my_str) const
{
	return (this->Compare(my_str) == 0);
}

//compare two Strings
bool yik::String::operator!=(const String & my_str) const
{
	return (this->Compare(my_str) != 0);
}

//compare two Strings
bool yik::String::operator>(const String & my_str) const
{
	return (this->Compare(my_str) > 0);
}

//compare two Strings
bool yik::String::operator>=(const String & my_str) const
{
	return (this->Compare(my_str) >= 0);
}

//compare two Strings
bool yik::String::operator<(const String & my_str) const
{
	return (this->Compare(my_str) < 0);
}

//compare two Strings
bool yik::String::operator<=(const String & my_str) const
{
	return (this->Compare(my_str) <= 0);
}

//compare two Strings
bool yik::String::operator==(const char * my_str) const
{
	return (this->Compare(my_str) == 0);
}

//compare two Strings
bool yik::String::operator!=(const char * my_str) const
{
	return (this->Compare(my_str) != 0);
}

//compare two Strings
bool yik::String::operator>(const char * my_str) const
{
	return (this->Compare(my_str) > 0);
}

//compare two Strings
bool yik::String::operator>=(const char * my_str) const
{
	return (this->Compare(my_str) >= 0);
}

//compare two Strings
bool yik::String::operator<(const char * my_str) const
{
	return (this->Compare(my_str) < 0);
}

//compare two Strings
bool yik::String::operator<=(const char * my_str) const
{
	return (this->Compare(my_str) <= 0);
}

//iostrem overloding of MyString
std::ostream & yik::operator<<(std::ostream & out, String & string)
{
	out << string.c_str();
	return out;
}

#pragma endregion

