#ifndef DUMBCOMPLEXNUMBER_H
#define DUMBCOMPLEXNUMBER_H

#include <iostream>

namespace paoo {
    class DumbComplexNumber {
    private:
    double* real;
    double* imaginary;

    public:
    DumbComplexNumber();
    DumbComplexNumber(double r, double i);
    DumbComplexNumber(const DumbComplexNumber& other) = delete;
    DumbComplexNumber(DumbComplexNumber&& other) = delete;
    ~DumbComplexNumber();

    DumbComplexNumber operator+(const DumbComplexNumber& other) const;
    DumbComplexNumber operator-(const DumbComplexNumber& other) const;
    DumbComplexNumber operator*(const DumbComplexNumber& other) const;
    DumbComplexNumber operator/(const DumbComplexNumber& other) const;

    friend std::ostream& operator<<(std::ostream& os, const DumbComplexNumber& complex);
    };
}

#endif //DUMBCOMPLEXNUMBER_H
