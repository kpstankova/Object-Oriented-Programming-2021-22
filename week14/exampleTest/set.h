#ifndef _SET_H_
#define _SET_H_
#include <iostream>

class Set {
protected:
    int* arr;
    int size;

private:
    void copy(const Set& other) {
        size = other.size;
        arr = new int[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = other.arr[i];
        }
    }
    void erase() {
        if (arr != nullptr) {
            delete[] arr;
        }
    }

public:
    Set() {
        size = 0;
        arr = nullptr;
    }
    // Set(const Set& other) {
    //     copy(other);
    // }
    // Set& operator=(const Set& other) {
    //     if(this != &other) {
    //         erase();
    //         copy(other);
    //     }

    //     return *this;
    // }
    virtual ~Set() {
        erase();
    }

    virtual bool member(int x) const = 0;
    // virtual int operator[](int index) = 0;
    int length() const {
        return size;
    }
    // virtual bool operator<(const Set*& other) const = 0;
    // virtual bool operator*(const Set*& other) const = 0;
    int operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("");
        }
        return arr[index];
    }
    bool operator<(const Set*& other) const {
        for (int i = 0; i < size; ++i) {
            if (!other->member(arr[i])) {
                return false;
            }
        }

        return true;
    }
    bool operator*(const Set*& other) const {
        for (int i = 0; i < size; ++i) {
            if (other->member(arr[i])) {
                return true;
            }
        }

        return false;
    }
    virtual void operator+=(const Set*& other) = 0;
};

#endif //_SET_H_