#include <iostream>
#include <utility>
#include "ComplexNumber.h"

int main() {

    try {


        paoo::ComplexNumber a(10.0, 2.0);
        paoo::ComplexNumber b = a;
        std::cout << "a before move: " << a << std::endl;
        std::cout << "b: " << b << std::endl;
        const paoo::ComplexNumber c = std::move(a);
        std::cout << "a after move: " << a << std::endl;
        std::cout << "c: " << c << std::endl;

        paoo::ComplexNumber cn1(3.0, 4.0);
        paoo::ComplexNumber cn2(1.0, 2.0);

        paoo::ComplexNumber sum = cn1 + cn2;
        paoo::ComplexNumber diff = cn1 - cn2;
        paoo::ComplexNumber prod = cn1 * cn2;
        paoo::ComplexNumber quot = cn1 / cn2;

        std::cout << "Sum: " << sum << std::endl;
        std::cout << "Difference: " << diff << std::endl;
        std::cout << "Product: " << prod << std::endl;
        std::cout << "Quotient: " << quot << std::endl;


    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
