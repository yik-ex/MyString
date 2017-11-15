#pragma once
#include <iostream>

namespace yik
{

	class String
	{
	private:
	
		char * str_ptr;
		size_t str_size;

	public:

		String();
		String(String &);
		String(const char *);
	
		~String();

		size_t GetLength();

		void Assign(String &);
		void Assign(const char *);

		char CharAt(const unsigned int) const;

		bool Append(String &);
		bool Append(const char *);

		int Compare(String &) const;
		int Compare(const char *) const;

		bool IsEmpty() const;
		void Clear();

		const char * c_str() const;

		friend std::ostream& operator<<(std::ostream&, String&);
	
	};

}
