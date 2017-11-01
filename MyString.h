#pragma once

class MyString
{
private:
	
	char * str_ptr;
	size_t str_size;

public:

	MyString();
	MyString(MyString &);
	MyString(const char *);
	
	~MyString();

	size_t GetLength();

	void Assign(MyString &);
	void Assign(const char *);

	char CharAt(const unsigned int) const;

	bool Append(MyString &);
	bool Append(const char *);

	int Compare(MyString &) const;
	int Compare(const char *) const;

	bool IsEmpty() const;
	void Clear();

	char const * c_str() const;
	
};

