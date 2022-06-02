#pragma once
#include "File.h"

class Directory : public File {
private:
    File** files;
    size_t size;

private:
    void resize() {
        ++size;
        File** temp = new File*[size];
        for (int i = 0; i < size - 1; ++i) {
            temp[i] = files[i]->clone();
        }
        for (int i = 0; i < size - 1; ++i) {
            delete files[i];
        }
        delete[] files;
        files = temp;
    }

    void erase() {
        for (int i = 0; i < size; ++i) {
            delete files[i];
        }
        delete[] files;
    }
    
public:
    //TODO
    Directory();
    Directory(const Directory& other);
    Directory& operator=(const Directory& other);
    ~Directory();

    void printContent() const override {
        std::cout << name << ": ";
        for (size_t i = 0; i < size; ++i)
        {
            std::cout << files[i]->getName() << ", ";
        }
        std::cout << std::endl;
    }

    File* operator+=(File* other) override {
        if (this != other) {
            resize();
            files[size] = other;
        }

        return this;
    }

    File* clone() const {
        return new Directory(*this);
    }
};