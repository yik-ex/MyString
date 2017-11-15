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

		size_t GetLength() const;

		void Assign(const String &);
		void Assign(const char *);

		char CharAt(const unsigned int) const;

		bool Append(const String &);
		bool Append(const char *);

		int Compare(const String &) const;
		int Compare(const char *) const;

		bool IsEmpty() const;
		void Clear();

		const char * c_str() const;

		friend std::ostream& operator<<(std::ostream&, String&);
		
		#pragma region Operators
		
		//assignment operator
		String& operator= (const String&);
		String& operator= (const char *);

		//compare operators
		bool operator== (const String&) const;
		bool operator!= (const String&) const;
		bool operator>  (const String&) const;
		bool operator>= (const String&) const;
		bool operator<  (const String&) const;
		bool operator<= (const String&) const;

		bool operator== (const char *) const;
		bool operator!= (const char *) const;
		bool operator>  (const char *) const;
		bool operator>= (const char *) const;
		bool operator<  (const char *) const;
		bool operator<= (const char *) const;
		
		#pragma endregion

	};

}
