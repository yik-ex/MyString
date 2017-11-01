#pragma once
#include <iostream>

class MyString
{
private:
	
	char * str_ptr;
	size_t str_size;

public:

	MyString();	//Don't need to check the other MyString, we use the assumption all the values are valid
	MyString(MyString *);
	MyString(const char *);
	
	~MyString();

	size_t GetLength();
	void Assign(MyString *);
	char CharAt(const unsigned int) const;
	bool Append(MyString *);
	int Compare(MyString *) const;
	bool IsEmpty() const;
	void Clear();

	//for this version only, for testing only, dangerus function
	char * GetStringPtr() const { return str_ptr; }
	
};

