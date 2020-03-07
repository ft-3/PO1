#include "vector.h"

namespace MyStuff {

    std::ostream& operator<<(std::ostream& os, vector& vec) {
        for (int i = 0; i < vec.size(); i++) {
            os << vec[i] << " ";
        }
        return os;
    }

    vector::vector(vector& orig) {
        _size = orig._size;
        int* tmp = new int[_size] {};
        for (int i = 0; i < _size; i++)
            tmp[i] = orig._data[i];
        _data = tmp;
    }

    void vector::push_back(int m) {
        _size += 1;
        int* tmp = new int[_size] {};
        for (int i = 0; i < _size - 1; i++) {
            tmp[i] = _data[i];
        }
        tmp[_size-1] = m;
        delete [] _data;
        _data = tmp;
    }

    void vector::pop_back(int k) {
        _size -= k;
        int* tmp = new int[_size] {};
        for (int i = 0; i < _size; i++) {
            tmp[i] = _data[i];
        }
        delete [] _data;
        _data = tmp;
    }
} 
