//
// Created by drago on 12/8/2024.
//

#include "DummyComplexNumber.h"

namespace paoo {
    DummyComplexNumber::DummyComplexNumber() : ComplexNumber(), dummy(new double(0)) {
        std::cout << "DummyComplexNumber created: " << *this << std::endl;
    }

    DummyComplexNumber::DummyComplexNumber(double r, double i, double dummy): ComplexNumber(r, i), dummy(new double(dummy)) {
        std::cout << "DummyComplexNumber created: " << *this << std::endl;
    }

    DummyComplexNumber::DummyComplexNumber(const ComplexNumber &c): ComplexNumber(c), dummy(new double(0)) {
        std::cout << "DummyComplexNumber created from ComplexNumber: " << *this << std::endl;
    }

    DummyComplexNumber::DummyComplexNumber(const ComplexNumber &c, double dummy): ComplexNumber(c),
    dummy(new double(dummy)) {
        std::cout << "DummyComplexNumber created from ComplexNumber: " << *this << std::endl;
    }

    DummyComplexNumber::DummyComplexNumber(const DummyComplexNumber &other) : ComplexNumber(other),
                                                                              dummy(new double(*other.dummy)) {
        std::cout << "DummyComplexNumber copied" << std::endl;
    }

    DummyComplexNumber & DummyComplexNumber::operator=(const DummyComplexNumber &other) {
        std::cout << "DummyComplexNumber assigned" << std::endl;
        ComplexNumber::operator=(other);
        double *originalDummy = this->dummy;
        this->dummy = new double(*other.dummy);
        delete originalDummy;
        return *this;
    }

    DummyComplexNumber::~DummyComplexNumber() {
        delete dummy;
        std::cout << "DummyComplexNumber destroyed" << std::endl;
    }

    DummyComplexNumber DummyComplexNumber::operator+(const DummyComplexNumber &other) const {
        std::cout << "DummyComplexNumber operator+" << std::endl;
        ComplexNumber aux = ComplexNumber::operator+(other);
        return DummyComplexNumber(aux, *other.dummy);
    }

    DummyComplexNumber DummyComplexNumber::operator-(const DummyComplexNumber &other) const {
        std::cout << "DummyComplexNumber operator-" << std::endl;
        ComplexNumber aux = ComplexNumber::operator-(other);
        return DummyComplexNumber(aux, *other.dummy);
    }

    DummyComplexNumber DummyComplexNumber::operator*(const DummyComplexNumber &other) const {
        std::cout << "DummyComplexNumber operator*" << std::endl;
        ComplexNumber aux = ComplexNumber::operator*(other);
        double temp = *dummy * *other.dummy;
        return DummyComplexNumber(aux, temp);
    }

    DummyComplexNumber DummyComplexNumber::operator/(const DummyComplexNumber &other) const {
        std::cout << "DummyComplexNumber operator/" << std::endl;
        ComplexNumber aux = ComplexNumber::operator/(other);
        double temp = (0 != *other.dummy) ? (*dummy / *other.dummy) : 0;
        return DummyComplexNumber(aux, temp);
    }

    DummyComplexNumber & DummyComplexNumber::operator+=(const DummyComplexNumber &other) {
        std::cout << "DummyComplexNumber operator+=" << std::endl;
        *this = *this + other;
        return *this;
    }

    DummyComplexNumber & DummyComplexNumber::operator-=(const DummyComplexNumber &other) {
        std::cout << "DummyComplexNumber operator-=" << std::endl;
        *this = *this - other;
        return *this;
    }

    DummyComplexNumber & DummyComplexNumber::operator*=(const DummyComplexNumber &other) {
        std::cout << "DummyComplexNumber operator*=" << std::endl;
        *this = *this * other;
        return *this;
    }

    paoo::DummyComplexNumber & paoo::DummyComplexNumber::operator/=(const DummyComplexNumber &other) {
        std::cout << "DummyComplexNumber operator/=" << std::endl;
        *this = *this / other;
        return *this;
    }

    std::ostream & operator<<(std::ostream &os, const DummyComplexNumber &dummmyComplex) {
        if (nullptr != dummmyComplex.real && nullptr != dummmyComplex.imaginary) {
            os << *dummmyComplex.real << " + " << *dummmyComplex.imaginary << "i + " << *dummmyComplex.dummy << "dummmy" << std::endl;
        } else {
            os << "null";
        }
        return os;
    }
}
