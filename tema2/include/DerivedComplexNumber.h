#ifndef DERIVEDCOMPLEXNUMBER_H
#define DERIVEDCOMPLEXNUMBER_H

#include "ComplexNumber.h"

namespace paoo {
    class DerivedComplexNumber : public ComplexNumber {
    public:
        DerivedComplexNumber();
        DerivedComplexNumber(double r, double i);
        ~DerivedComplexNumber();
    };
}

#endif //DERIVEDCOMPLEXNUMBER_H
