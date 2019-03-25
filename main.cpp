#include <iostream>
#include "tstring.h"
#include "operatory.h"

using namespace std;
using namespace MojeOperatory;
// komentarz

TString fabryka( const char* s ) {
	return TString(s);
}

int main() try {
	TString s1; 
	TString s2("drugi obiekt");
	TString s3 { s2 }; // uniwersalna = jednolita inicjalizacja
	s1 = s2;
	TString s4 { std::move(s1) };
	TString s5 = fabryka("moja fabryka");

	s2.insert(0,"poczatek|");
	s2.insert(s2.size(),"|koniec");
	s2.insert(15,"[srodek]");
	s2.insert(0,'A');
	s2.insert(s2.length(),'Z');
	cout << s2 << endl;
	s1 = "s1111111111111";
	s3 = "s333333333";
	cout << s1+s3 << endl;
	s1 = s3 + "cos na koniec s1";
	cout << s1 << endl;
	s1 += s1;
	cout << s1 << endl;
	cout << "-------------------" << endl;
} catch ( ... ) {
	cout << "THE END" << endl;
}
