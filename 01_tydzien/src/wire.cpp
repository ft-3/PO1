#include "wire.h"

////////////////////////////////////////
// Constructors
////////////////////////////////////////
QuantumWire::QuantumWire(double length, int size): 
                    _length(length), _size(size), _particles(new bool[size]) {
    for (int i = 0; i < length; i++)
        _particles[i] = rand() % 2;
};

QuantumWire::QuantumWire(const QuantumWire& wire) {
   _length = wire._length;
   _size = wire._size;
   _particles = new bool[_size];
   for (int i = 0; i < _size; i++)
       _particles[i] = wire._particles[i];
}

QuantumWire::QuantumWire(const QuantumWire&& wire) {
   _length = wire._length;
   _size = wire._size;
   _particles = new bool[_size];
   for (int i = 0; i < _size; i++)
       _particles[i] = wire._particles[i];
   delete [] _particles;
   _particles = nullptr;
}

////////////////////////////////////////
// Operators
////////////////////////////////////////
QuantumWire QuantumWire::operator*=(const double mult) {
    _length *= mult;
    return *this;
}

QuantumWire operator*(QuantumWire& lhs, const double rhs) {
    lhs *= rhs;
    return lhs;
}

QuantumWire operator*(const double lhs, QuantumWire& rhs) {
    rhs *= lhs;
    return rhs;
}

QuantumWire QuantumWire::operator!(void) {
    for (int i = 0; i < this->_length; i++)
        this->_particles[i] = !this->_particles[i];
    return *this;
}

bool QuantumWire::operator[](int i) {
    if (i < _length) return _particles[i];
    else return false;
}

std::ostream& operator<<(std::ostream& os, const QuantumWire& wire) {
    os << "length: ";
    os << std::to_string(wire._length);
    os << ", quanta:";
    for (int i = 0 ; i < wire._size; i++)
        os << (" " + std::to_string(wire._particles[i]));
    return os;
}
