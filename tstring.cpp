#include "tstring.h"
#include <iostream>
#include <stdexcept>
using namespace std;

TString::TString( const char* s ) : ptr(nullptr), len(0) {
	if ( s != nullptr ) {
		len = strlen(s);
		ptr = new char[len+1]; // +1 bo /0 konczoace lancuch tez musi sie zmiescic
		strcpy(ptr,s);
	}
	#ifdef DEBUG
		cout << "TString c-tor " << len << " : " << ( ptr ? ptr : "pusty" ) << endl;
	#endif
}

TString::~TString() {
	#ifdef DEBUG
		cout << "TString d-tor " << len << " : " << ( ptr ? ptr : "pusty" ) << endl;
	#endif	
	delete [] ptr;
}


TString::TString( const TString& s ) : ptr(nullptr), len(s.len) {
	if ( len>0 ) {
		ptr = new char[len+1];
		strcpy(ptr,s.ptr);
	}
	#ifdef DEBUG
		cout << "TString cc-tor " << len << " : " << ( ptr ? ptr : "pusty" ) << endl;
	#endif		
}


TString& TString::operator=( const TString& s ) {
	if ( this != &s ) {
		delete [] ptr;
		ptr = nullptr;
		len = s.len;
		if ( len>0 ) {
			ptr = new char[len+1];
			strcpy(ptr,s.ptr);
		}
	}
	#ifdef DEBUG
		cout << "TString operator= " << len << " : " << ( ptr ? ptr : "pusty" ) << endl;
	#endif		
	return *this;
}


TString::TString( TString&& s ) : ptr(s.ptr), len(s.len) {
	s.ptr = nullptr;
	s.len = 0;
	#ifdef DEBUG
		cout << "TString mvc-tor " << len << " : " << ( ptr ? ptr : "pusty" ) << endl;
	#endif			
}

TString& TString::operator=( TString&& s ) {
	if ( this != &s ) {
		delete [] ptr;
		len = s.len;
		ptr = s.ptr;
		s.len = 0;
		s.ptr = nullptr;
	}
	#ifdef DEBUG
		cout << "TString move operator= " << len << " : " << ( ptr ? ptr : "pusty" ) << endl;
	#endif			
	return *this;
}


char& TString::operator[]( size_t n ) {
	if ( ptr == nullptr ) throw invalid_argument("pusty obiekt");
	if ( n >= 0 && n < len ) return ptr[n];
	throw out_of_range("indeks spoza zakresu");
}

const char& TString::operator[]( size_t n ) const {
	if ( ptr == nullptr ) throw invalid_argument("pusty obiekt");
	if ( n >= 0 && n < len ) return ptr[n];
	throw out_of_range("indeks spoza zakresu");
}


