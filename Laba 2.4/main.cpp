#include "Vector.h"

int main() {
    Vector vec1(3);
    std::cin >> vec1;
    std::cout << "Vector 1: " << vec1 << std::endl;

    Vector vec2(3);
    std::cin >> vec2;
    std::cout << "Vector 2: " << vec2 << std::endl;
    std::cout << std::endl;

    Vector sum = vec1 + vec2;
    std::cout << "Sum of vectors: " << sum << std::endl;

    if (vec1 == vec2) {
        std::cout << "Vectors are equal." << std::endl;
    } else {
        std::cout << "Vectors are not equal." << std::endl;
    }

    std::cout << "Norm of vector 1: " << vec1.norm() << std::endl;

    return 0;
}
