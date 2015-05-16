//
//  Integer.h
//  DMColloquium
//
//  Created by Ilya Kulebyakin on 4/28/15.
//  Copyright (c) 2015 Ilya Kulebyakin. All rights reserved.
//

#ifndef __DMColloquium__Integer__
#define __DMColloquium__Integer__

#include "NaturalNumber.h"
#include <vector>
#include <string>

class Integer : public NaturalNumber {
private:
    bool isPositive;
public:
    Integer();
    Integer(std::vector<unsigned int> digits, bool isPositive);
    Integer(NaturalNumber natural, bool isPositive):NaturalNumber{natural},isPositive{isPositive}{};
    //("2346234623452346234623462346") ("-234623452346234623462346") ("+234652345234623462346")
    Integer ADD_ZZ_Z(Integer const&);
    friend std::istream& operator>> (std::istream& str, Integer& integer);
};


#endif /* defined(__DMColloquium__Integer__) */
