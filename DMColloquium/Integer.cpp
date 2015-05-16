//
//  Integer.cpp
//  DMColloquium
//
//  Created by Ilya Kulebyakin on 4/28/15.
//  Copyright (c) 2015 Ilya Kulebyakin. All rights reserved.
//

#include "Integer.h"
using namespace std;

Integer::Integer() {
    digitBlocks = vector<unsigned int>(1);
    digitBlocks[0] = 0;
    isPositive = true;
}

Integer::Integer(vector<unsigned int> digits, bool isPositive) {
    digitBlocks = digits;
    this->isPositive = isPositive;
}

std::istream& operator>> (std::istream& str, Integer& integer) {
    string numString;
    getline(str, numString);
    
    if (!isdigit(numString[0])) {
        integer.isPositive = (numString[0] != '-');
        numString = numString.substr(1);
    } else {
        integer.isPositive = true;
    }
    
    integer.setDigitsFromString(numString);
    
    NaturalNumber natNum;
    
    return str;
}


Integer Integer::ADD_ZZ_Z(Integer n) {
	if (this->POZ_Z_D() == 0) return n;
	if (n.POZ_Z_D() == 0) return *this;
	if (this->POZ_Z_D() == 1 && n.POZ_Z_D() == 1) 
		return Integer(this->ADD_NN_N(n), true);
	if (this->POZ_Z_D() == -1 && n.POZ_Z_D() == 1)
	{
		switch (this->COM_NN_D(n))
		{
			case 1: return Integer(n.SUB_NN_N(this->ABS_Z_N()), true);
			case 0: return Integer();
			case 2: return Integer(this->ABS_Z_N()->SUB_NN_N(n), false);
		}
	}
	if (this->POZ_Z_D() == 1 && n.POZ_Z_D() == -1)
	{
		switch (this->COM_NN_D(n))
		{
			case 1: return Integer(n.ABS_Z_N().SUB_NN_N(this), false);
			case 0: return Integer();
			case 2: return Integer(this->SUB_NN_N(n.ABS_Z_N()), false);
		}
	}
	if (this->POZ_Z_D() == -1 && n.POZ_Z_D() == -1)
		return Integer(this->ABS_Z_N()->ADD_NN_N(n.ABS_Z_N), false);
}
