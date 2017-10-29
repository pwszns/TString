#include "tstring.h"
#include <iostream>
#include <stdexcept>
using namespace std;

// definicja sk³adowej statycznej klasy TString
size_t TString::licznik; // pola statyczne maj¹ gwarancjê inicjalizacji 0

TString::TString( const char* s ) : ptr(nullptr), len(0) {
	++licznik;
	if ( s != nullptr ) {
		len = strlen(s);
		ptr = new char[len+1]; // +1 bo /0 konczoace lancuch tez musi sie zmiescic
		strcpy(ptr,s);
	}
	#ifdef DEBUG
		cout << licznik << " TString c-tor " << len << " : " << ( ptr ? ptr : "pusty" ) << endl;
	#endif
}

TString::~TString() {
	--licznik;
	#ifdef DEBUG
		cout << licznik << " TString d-tor " << len << " : " << ( ptr ? ptr : "pusty" ) << endl;
	#endif	
	delete [] ptr;
}


TString::TString( const TString& s ) : ptr(nullptr), len(s.len) {
	++licznik;
	if ( len>0 ) {
		ptr = new char[len+1];
		strcpy(ptr,s.ptr);
	}
	#ifdef DEBUG
		cout << licznik << " TString cc-tor " << len << " : " << ( ptr ? ptr : "pusty" ) << endl;
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
	++licznik;
	s.ptr = nullptr;
	s.len = 0;
	#ifdef DEBUG
		cout << licznik << " TString mvc-tor " << len << " : " << ( ptr ? ptr : "pusty" ) << endl;
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


char* TString::insert( size_t pos, const char* s) {
	if ( pos >= 0 && pos <= len ) {
		size_t oldlen = len;
		if ( s != nullptr ) len = len + strlen(s);
		if ( len > 0 ) {
			char* tmp = new char[ len+1 ];
			if ( ptr != nullptr ) strcpy( tmp, ptr );
			if ( s!= nullptr )
			for ( auto i=pos; i<pos+strlen(s); ++i ) {
				tmp[i] = s[i-pos];
			}
			if ( s != nullptr && ptr != nullptr )
			for ( auto i=pos; i<oldlen; ++i ) {
				tmp[i+strlen(s)] = ptr[i];
			}
			tmp[len] = '\0'; // char koñcz¹cy ³añcuch znakowy
		    delete [] ptr;
	    	ptr = tmp; // przekazanie praw w³asnoœci z tmp do ptr
	    }  
	    if ( ptr != nullptr ) return ptr+pos; else return ptr;
	} else {
		throw out_of_range("argument spoza zakresu");
	}
	return ptr; // ta linia nigdy nie bêdzie wykonana
}


char* TString::insert( size_t pos, char c ) {
	return insert( pos, string( 1, c ).c_str() );
}


