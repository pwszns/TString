#include <iostream>
#include "tstring.h"
#include "operatory.h"

using namespace std;
using namespace MojeOperatory;

TString fabryka( const char* s ) {
	return TString(s);
}

int main() {
	TString s1; 
	TString s2("drugi obiekt");
	TString s3 { s2 }; // uniwersalna = jednolita inicjalizacja
	s1 = s2;
	//s1 = "tralala";
	TString s4 { std::move(s1) };
	TString s5 = fabryka("moja fabryka");
	s4 = move(s5);
	s4 = fabryka("ostatni obiekt");

    for ( auto c : s4 ) cout << c << "-";
    for ( auto& c : s4) c = toupper(c);
    cout << endl;
    cout << s4 << endl;
    cin >> s4;
    cout << s4 << endl;
	cout << "-------------------" << endl;
}
