#include "DerivedComplexNumber.h"

namespace paoo {
    DerivedComplexNumber::DerivedComplexNumber() : ComplexNumber() {
        std::cout << "DerivedComplexNumber created" << std::endl;
    }

    DerivedComplexNumber::DerivedComplexNumber(double r, double i) : ComplexNumber(r, i) {
        std::cout << "DerivedComplexNumber created" << std::endl;
    }

    DerivedComplexNumber::~DerivedComplexNumber() {
        std::cout << "DerivedComplexNumber destroyed" << std::endl;
    }
}
