#pragma once
#include <cstring>
#include <iostream>

enum FileType {
    DUMMY = 0,
    REGULAR,
    DIRECTORY,
    LINK
};

class File {
protected:
    char* name;
    FileType type;

private:
    void copy(const File& other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        type = other.type;
    }

    void erase() {
        delete[] name;
    }

public:
    File() {
        name = new char[1];
        name[0] = '\0';
        type = DUMMY;
    }
    File(const File& other) {
        copy(other);
    }
    File& operator=(const File& other) {
        if (this != &other) {
            erase();
            copy(other);
        }
        return *this;
    }
    virtual ~File() {
        erase();
    }

    void rename(const char* newName) {
        erase();
        name = new char[strlen(newName) + 1];
        strcpy(name, newName);
    }

    virtual void printContent() const = 0;
    virtual File* operator+=(File* other) = 0;
    virtual File* clone() const = 0;

    const FileType& getFileType() const {
        return type;
    }
    const char* getName() const {
        return name;
    }
};