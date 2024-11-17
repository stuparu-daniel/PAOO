#include "ComplexNumber.h"
#include <utility>

namespace paoo {

    ComplexNumber::ComplexNumber() : real(new double(0)), imaginary(new double(0)) {
        std::cout << "ComplexNumber created: " << *this << std::endl;
    }

    ComplexNumber::ComplexNumber(const double r, const double i) : real(new double(r)), imaginary(new double(i)) {
        std::cout << "ComplexNumber created: " << *this << std::endl;
    }

    // Copy constructor
    ComplexNumber::ComplexNumber(const ComplexNumber& other) : real(new double(*other.real)), imaginary(new double(*other.imaginary)) {
        std::cout << "ComplexNumber copied" << std::endl;
    }

    // Move constructor
    ComplexNumber::ComplexNumber(ComplexNumber&& other) noexcept : real(other.real), imaginary(other.imaginary) {
        other.real = nullptr;
        other.imaginary = nullptr;
        std::cout << "ComplexNumber moved" << std::endl;
    }

    ComplexNumber::~ComplexNumber() {
        delete real;
        delete imaginary;
        std::cout << "ComplexNumber destroyed" << std::endl;
    }

    ComplexNumber ComplexNumber::operator+(const ComplexNumber& other) const {
        return {*real + *other.real, *imaginary + *other.imaginary};
    }

    ComplexNumber ComplexNumber::operator-(const ComplexNumber& other) const {
        return {*real - *other.real, *imaginary - *other.imaginary};
    }

    ComplexNumber ComplexNumber::operator*(const ComplexNumber& other) const {
        double newReal = (*real * *other.real) - (*imaginary * *other.imaginary);
        double newImaginary = (*real * *other.imaginary) + (*imaginary * *other.real);
        return {newReal, newImaginary};
    }

    ComplexNumber ComplexNumber::operator/(const ComplexNumber& other) const {
        if (0 == *other.real && 0 == *other.imaginary) {
            throw std::runtime_error("Division by zero complex number");
        }
        const double denominator = (*other.real * *other.real) + (*other.imaginary * *other.imaginary);
        const double newReal = ((*real * *other.real) + (*imaginary * *other.imaginary)) / denominator;
        const double newImaginary = ((*imaginary * *other.real) - (*real * *other.imaginary)) / denominator;
        return {newReal, newImaginary};
    }

    std::ostream& operator<<(std::ostream& os, const ComplexNumber& complex) {
        if (nullptr != complex.real && nullptr != complex.imaginary) {
            os << *complex.real << " + " << *complex.imaginary << "i";
        } else {
            os << "null";
        }
        return os;
    }
}

