#pragma once
#include "set.h"

class ArraySet : public Set {
private:
    const int n;

public:
    ArraySet(int _n) : Set(), n(_n) {
        arr = new int[n];
    }

    bool insert(int x) {
        if (size < n && !member(x)) {
            arr[size++] = x;
            return true;
        }

        return false;
    }

    bool member(int x) const override {
        for (int i = 0; i < size; ++i) {
            if (arr[i] == x) {
                return true;
            }
        }

        return false;
    }
    
    void operator+=(const Set*& other) override {
        
    }
};