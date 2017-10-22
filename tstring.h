#ifndef TSTRING_H
#define TSTRING_H

#include <cstring>
#include "operatory.h"

class TString {
	public:
		TString( const char* s = nullptr ); // c-tor
		TString( const TString& s ); // cc-tor
		TString( TString&& s ); // mvc-tor
		~TString(); // d-tor
		TString& operator=( const TString& s ); // copy operator=
		TString& operator=( TString&& s ); // move operator=
		
		char& operator[]( size_t n );
		const char& operator[]( size_t n ) const;
		
		char* begin() { return ptr; }
		char* end() { return ptr+len; }
		size_t length() const { return len; } 
		size_t size() const { return len; } 
		void clear() { delete[] ptr; ptr= nullptr; len = 0; }
		bool empty() const { return len ? false: true; }
		char& front() { return *ptr; }
		const char& front() const { return *ptr; }
		char& back() { return *(ptr+len-1); }
		const char& back() const { return *(ptr+len-1); }
		
		friend std::ostream& MojeOperatory::operator<<(std::ostream& strumien, const TString& s);
		friend std::istream& MojeOperatory::operator>>(std::istream& strumien, TString& s);
	private:
		char* ptr = nullptr;
		std::size_t len = 0;
};

#endif // TSTRING_H


