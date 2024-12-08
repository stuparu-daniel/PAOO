//
// Created by drago on 12/8/2024.
//

#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include <iostream>

namespace paoo {
    class ComplexNumber {

    protected:
        double* real;
        double* imaginary;

    public:
        ComplexNumber();
        ComplexNumber(double r, double i);
        ComplexNumber(const ComplexNumber& other);
        ComplexNumber(ComplexNumber&& other) noexcept;
        ComplexNumber& operator=(const ComplexNumber& other);
        ~ComplexNumber();

        ComplexNumber operator+(const ComplexNumber& other) const;
        ComplexNumber operator-(const ComplexNumber& other) const;
        ComplexNumber operator*(const ComplexNumber& other) const;
        ComplexNumber operator/(const ComplexNumber& other) const;

        ComplexNumber& operator+=(const ComplexNumber& other);
        ComplexNumber& operator-=(const ComplexNumber& other);
        ComplexNumber& operator*=(const ComplexNumber& other);
        ComplexNumber& operator/=(const ComplexNumber& other);

        friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& complex);
    };
}
#endif //COMPLEXNUMBER_H
