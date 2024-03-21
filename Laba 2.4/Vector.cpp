#include "Vector.h"

Vector::Vector(int n) : size(n) {
    elements = new int[size];
}

Vector::Vector() : size(0), elements(nullptr) {}

Vector::Vector(const Vector &other) : size(other.size) {
    elements = new int[size];
    for (int i = 0; i < size; ++i) {
        elements[i] = other.elements[i];
    }
}

Vector::~Vector() {
    delete[] elements;
}

int Vector::getSize() const {
    return size;
}

int Vector::getElement(int index) const {
    return elements[index];
}

void Vector::setElement(int index, int value) {
    elements[index] = value;
}

Vector Vector::operator+(const Vector &other) const {
    if (size != other.size) {
        std::cerr << "Vectors must have the same size for addition." << std::endl;
        return Vector();
    }

    Vector result(size);
    for (int i = 0; i < size; ++i) {
        result.elements[i] = elements[i] + other.elements[i];
    }
    return result;
}

bool Vector::operator==(const Vector &other) const {
    if (size != other.size) {
        return false;
    }
    for (int i = 0; i < size; ++i) {
        if (elements[i] != other.elements[i]) {
            return false;
        }
    }
    return true;
}

double Vector::norm() const {
    double sumOfSquares = 0.0;
    for (int i = 0; i < size; ++i) {
        sumOfSquares += elements[i] * elements[i];
    }
    return sqrt(sumOfSquares);
}

std::ostream &operator<<(std::ostream &out, const Vector &vec) {
    out << "(";
    for (int i = 0; i < vec.size; ++i) {
        out << vec.elements[i];
        if (i != vec.size - 1) {
            out << ", ";
        }
    }
    out << ")";
    return out;
}

std::istream &operator>>(std::istream &in, Vector &vec) {
    std::cout << "Enter vector elements:" << std::endl;
    for (int i = 0; i < vec.size; ++i) {
        in >> vec.elements[i];
    }
    return in;
}

Vector::operator std::string() const {
    std::string result = "(";
    for (int i = 0; i < size; ++i) {
        result += std::to_string(elements[i]);
        if (i != size - 1) {
            result += ", ";
        }
    }
    result += ")";
    return result;
}

int &Vector::operator[](int index) {
    return elements[index];
}

const int &Vector::operator[](int index) const {
    return elements[index];
}
