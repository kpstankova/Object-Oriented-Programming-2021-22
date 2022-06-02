#pragma once
#include "set.h"

class IntRange : public Set {
private:
    int start;
    int end;

public:
    IntRange(int _start, int _end) : Set(), start(_start), end(_end) {
        if (_end < _start) {
            throw std::invalid_argument("Start cannot be after end");
        }
        size = _end - _start + 1;
        arr = new int[size];
        for (int i = start; i < end; ++i) {
            arr[i - start] = i;
        }
    }
    IntRange(const IntRange& other) : Set(other) {
        start = other.start;
        end = other.end;
    }
    IntRange& operator=(const IntRange& other) {
        if (this != &other) {
            Set::operator=(other);
            start = other.start;
            end = other.end;
        }

        return *this;
    }
    ~IntRange() = default;

    bool member(int x) const override {
        return x <= end && x >= start;
    }
    void operator+=(const Set*& other) override {
        
    }
};