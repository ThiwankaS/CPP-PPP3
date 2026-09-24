#include <iostream>
#include <exception>
#include <stdexcept>

class Array {
        int         *_array;
        unsigned int _size;
    public:
        Array(unsigned int size = 0);
        virtual ~Array();
        void add(int value);
        void delItem(unsigned int index);
        unsigned int getSize() const;
        int& operator[] (unsigned int index);
};

Array::Array(unsigned int size) : _array(nullptr), _size(size) {
    if(size > 0) {
        this->_array = new int[this->_size];
    }
}

Array::~Array() {
    delete [] this->_array;
}

void Array::add(int value) {
    if(this->_size == 0) {
        this->_array = new int[1];
    } else {
        int *_temp = new int [this->_size + 1];
        for(unsigned int i = 0; i < this->_size; ++i) {
            _temp[i] = this->_array[i];
        }
        delete [] this->_array;
        this->_array = _temp;
    }
    this->_array[this->_size++] = value;
}

void Array::delItem(unsigned int index) {
    if(index >= this->_size) {
        return;
    }

    if(this->_size == 1) {
       if(index == 0) {
            delete [] this->_array;
            this->_array = nullptr;
       }
    } else { 
        int *_temp = new int[this->_size - 1];
        for(unsigned int i = 0, j = 0; i < this->_size; ++i, ++j) {
            if(i == index) {
                --j;
                continue;
            }
            _temp[j] = this->_array[i];
        }
        delete [] this->_array;
        this->_array = _temp;
    }
    this->_size--;
}

unsigned int Array::getSize(void) const {
    return this->_size;
}

int& Array::operator[] (unsigned int index) {
    if(index >= this->_size) {
        throw std::out_of_range("array index out of bound");
    }
    return this->_array[index];
}

int main(void) {

    Array A(10);

    for(int i = 0; i < A.getSize(); ++i) {
        A[i] = i;
    }

    for(int i = 0; i < A.getSize(); ++i) {
        std::cout << A[i] << " ";
    }
    std::cout << "\n";

    std::cout << "after initializing size : " << A.getSize() << "\n";
    A.add(99);
    std::cout << "after added item size : " << A.getSize() << "\n";
    for(int i = 0; i < A.getSize(); ++i) {
        std::cout << A[i] << " ";
    }
    std::cout << "\n";
    
    A.delItem(3);
    std::cout << " after removed item size : " << A.getSize() << "\n";
    for(int i = 0; i < A.getSize(); ++i) {
        std::cout << A[i] << " ";
    }
    std::cout << "\n";

    return EXIT_SUCCESS;
}
