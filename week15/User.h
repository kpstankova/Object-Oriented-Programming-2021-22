#pragma once
#include "File.h"

class User {
private:
    char* username;
    char* password;
    File** files;
    int size;

private:
    void resize() {
        File** temp = new File*[size + 1];
        for (int i = 0; i < size; ++i) {
            temp[i] = files[i]->clone();
        }
        erase();
        files = temp;
    }

    void erase() {
        for (int i = 0; i < size; ++i) {
            delete[] files[i];
        }
        delete files;
    }

public:
//TODO
    User();
    User(const User& other);
    User& operator=(const User& other);
    ~User();

    void addFile(File* file) {
        resize();
        files[size] = file->clone();
    } 
};