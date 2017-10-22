#ifndef OPERATORY_H
#define OPERATORY_H

#include <iostream>
#include <fstream>

class TString;

namespace MojeOperatory {
	
	std::ostream& operator<<(std::ostream& strumien, const TString& s);
	std::istream& operator>>(std::istream& strumien, TString& s);
}


#endif
