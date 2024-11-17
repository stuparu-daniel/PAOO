#include "DumbComplexNumber.h"

namespace paoo {
    DumbComplexNumber::DumbComplexNumber() : real(new double(0)), imaginary(new double(0)) {
        std::cout << "DumbComplexNumber created: " << *this << std::endl;
    }

    DumbComplexNumber::DumbComplexNumber(const double r, const double i) : real(new double(r)), imaginary(new double(i)) {
        std::cout << "DumbComplexNumber created: " << *this << std::endl;
    }

    DumbComplexNumber::~DumbComplexNumber() {
        delete real;
        delete imaginary;
        std::cout << "DumbComplexNumber destroyed" << std::endl;
    }

    DumbComplexNumber DumbComplexNumber::operator+(const DumbComplexNumber& other) const {
        return {*real + *other.real, *imaginary + *other.imaginary};
    }

    DumbComplexNumber DumbComplexNumber::operator-(const DumbComplexNumber& other) const {
        return {*real - *other.real, *imaginary - *other.imaginary};
    }

    DumbComplexNumber DumbComplexNumber::operator*(const DumbComplexNumber& other) const {
        double newReal = (*real * *other.real) - (*imaginary * *other.imaginary);
        double newImaginary = (*real * *other.imaginary) + (*imaginary * *other.real);
        return {newReal, newImaginary};
    }

    DumbComplexNumber DumbComplexNumber::operator/(const DumbComplexNumber& other) const {
        if (0 == *other.real && 0 == *other.imaginary) {
            throw std::runtime_error("Division by zero complex number");
        }
        const double denominator = (*other.real * *other.real) + (*other.imaginary * *other.imaginary);
        const double newReal = ((*real * *other.real) + (*imaginary * *other.imaginary)) / denominator;
        const double newImaginary = ((*imaginary * *other.real) - (*real * *other.imaginary)) / denominator;
        return {newReal, newImaginary};
    }

    std::ostream& operator<<(std::ostream& os, const DumbComplexNumber& complex) {
        if (nullptr != complex.real && nullptr != complex.imaginary) {
            os << *complex.real << " + " << *complex.imaginary << "i";
        } else {
            os << "null";
        }
        return os;
    }
}
