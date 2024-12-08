//
// Created by drago on 12/8/2024.
//

#include <iostream>
#include <utility>
#include "ComplexNumber.h"
#include "DummyComplexNumber.h"

int main() {

    try {
        paoo::ComplexNumber a(10.0, 2.0);
        paoo::ComplexNumber b = a;
        std::cout << "a before move: " << a << std::endl;
        std::cout << "b: " << b << std::endl;
        const paoo::ComplexNumber c = std::move(a);
        std::cout << "a after move: " << a << std::endl;
        std::cout << "c: " << c << std::endl;

        std::cout << std::endl << std::endl;

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

        std::cout << std::endl << std::endl;

        paoo::ComplexNumber d(1.0, 1.0);
        std::cout << "Before self assignment d: " << d << std::endl;
        d = d;
        std::cout << "After self assignment d: " << d << std::endl;
        paoo::ComplexNumber z(2.0, 2.0);
        std::cout << "Before assignment z: " << z << std::endl;
        z = d;
        std::cout << "After assignment z: " << z << std::endl;

        std::cout << std::endl << std::endl;

        paoo::ComplexNumber z1(1.0, 1.0);
        paoo::ComplexNumber z2(2.0, 2.0);
        z1 += z2;
        std::cout << "z1: " << z1 << std::endl;
        paoo::ComplexNumber z3(2.0, 2.0);
        z3 -= z2;
        std::cout << "z3: " << z3 << std::endl;
        paoo::ComplexNumber z4(2.0, 2.0);
        z4 *= z3;
        std::cout << "z4: " << z4 << std::endl;
        paoo::ComplexNumber z5(2.0, 2.0);
        z5 /= z2;
        std::cout << "z5: " << z5 << std::endl;

        paoo::ComplexNumber z6(2.0, 2.0);
        z6 *= z6;
        std::cout << "z6: " << z6 << std::endl;

    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        paoo::DummyComplexNumber a(1.0, 1.0, 1.0);
        paoo::DummyComplexNumber b(1.0, 2.0, 3.0);
        paoo::DummyComplexNumber c = a;
        std::cout << "c: " << c << std::endl;
        paoo::DummyComplexNumber d(10.0, 10.0, 10.0);
        d = d;
        std::cout << "d: " << d << std::endl;
        paoo::DummyComplexNumber e(d);
        std::cout << "e: " << e << std::endl;
        paoo::ComplexNumber f(1.0, 2.0);
        paoo::DummyComplexNumber g(f, 7.0);
        std::cout << "g: " << g << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
