#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include <iostream>

namespace paoo {
    class ComplexNumber {

    private:
        double* real;
        double* imaginary;

    public:
        ComplexNumber();
        ComplexNumber(double r, double i);
        ComplexNumber(const ComplexNumber& other);
        ComplexNumber(ComplexNumber&& other) noexcept;
        ~ComplexNumber();

        ComplexNumber operator+(const ComplexNumber& other) const;
        ComplexNumber operator-(const ComplexNumber& other) const;
        ComplexNumber operator*(const ComplexNumber& other) const;
        ComplexNumber operator/(const ComplexNumber& other) const;

        friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& complex);
    };


}
#endif //COMPLEXNUMBER_H
