#pragma once
#include <iostream>
#include <cmath>

class Vector {
private:
    int *elements;
    int size;

public:
    Vector(int n);
    Vector();
    Vector(const Vector &other);
    ~Vector();

    int getSize() const;
    int getElement(int index) const;
    void setElement(int index, int value);

    Vector operator+(const Vector &other) const;
    bool operator==(const Vector &other) const;
    double norm() const;

    friend std::ostream &operator<<(std::ostream &out, const Vector &vec);
    friend std::istream &operator>>(std::istream &in, Vector &vec);
    operator std::string() const;

    int &operator[](int index);
    const int &operator[](int index) const;
};
