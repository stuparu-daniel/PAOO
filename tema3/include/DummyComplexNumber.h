//
// Created by drago on 12/8/2024.
//

#ifndef DUMMYCOMPLEXNUMBER_H
#define DUMMYCOMPLEXNUMBER_H

#include <iostream>
#include "ComplexNumber.h"

namespace paoo {
    class DummyComplexNumber : public ComplexNumber {

    private:
        double *dummy;

    public:
        DummyComplexNumber();
        DummyComplexNumber(double r, double i, double dummy);
        DummyComplexNumber(const ComplexNumber &c);
        DummyComplexNumber(const ComplexNumber &c, double dummy);
        DummyComplexNumber(const DummyComplexNumber& other);
        DummyComplexNumber& operator=(const DummyComplexNumber& other);
        ~DummyComplexNumber();

        DummyComplexNumber operator+(const DummyComplexNumber& other) const;
        DummyComplexNumber operator-(const DummyComplexNumber& other) const;
        DummyComplexNumber operator*(const DummyComplexNumber& other) const;
        DummyComplexNumber operator/(const DummyComplexNumber& other) const;

        DummyComplexNumber& operator+=(const DummyComplexNumber& other);
        DummyComplexNumber& operator-=(const DummyComplexNumber& other);
        DummyComplexNumber& operator*=(const DummyComplexNumber& other);
        DummyComplexNumber& operator/=(const DummyComplexNumber& other);

        friend std::ostream& operator<<(std::ostream& os, const DummyComplexNumber& complex);
    };
}

#endif //DUMMYCOMPLEXNUMBER_H
