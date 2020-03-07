# pragma once

#include <iostream>
namespace MyStuff {
class vector {
private:
    int _size;
    int* _data;

public:
    vector() : _size(0), _data(nullptr) {};
    vector(int size) : _size(size), _data(new int[size] {}) {};
    vector(vector&);
    ~vector() { delete [] _data; }

    int* begin() { return &_data[0]; }
    int* end() { return &_data[_size-1]; }

    void push_back(int);
    void pop_back(int);
    void pop_back() { pop_back(1); }
    inline int size() { return _size; }

    friend std::ostream& operator<<(std::ostream&, vector&);
    int& operator[](int pos) { 
        return _data[pos];
    }

    vector& operator=(vector& orig) {
        _size = orig._size;
        int* tmp = new int[_size] {};
        for (int i = 0; i < _size; i++)
            tmp[i] = orig._data[i];
         if (_data) delete [] _data;
        _data = tmp;
        return *this;
    }

};
}
