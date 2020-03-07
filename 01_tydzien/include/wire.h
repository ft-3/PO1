#pragma once

#include <cmath>
#include <iostream>

class QuantumWire {
private:
    double _length;
    int _size;
    bool* _particles;
public:
    // Constructors
    QuantumWire(): _length(0), _particles(nullptr) {};
    QuantumWire(double, int);
    QuantumWire(const QuantumWire&);
    QuantumWire(const QuantumWire&&);

    // Operators
    QuantumWire operator*=(const double);
    QuantumWire operator!(void);
    bool operator[](int);
    friend std::ostream& operator<<(std::ostream&, const QuantumWire&);

};

std::ostream& operator<<(std::ostream&, const QuantumWire&);
QuantumWire operator*(QuantumWire, const double);
QuantumWire operator*(const double, QuantumWire&);
