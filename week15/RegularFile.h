#pragma once
#include "File.h"

class RegularFile : public File {
private:
    char* content;
    char* extension;

private:
    void copy(const RegularFile& other) {
        content = new char[strlen(other.content) + 1];
        strcpy(content, other.content);
        extension = new char[strlen(other.extension) + 1];
        strcpy(extension, other.extension);
    }

    void erase() {
        delete[] content;
        delete[] extension;
    }

public:
    RegularFile() : File() {
        content = new char[1];
        content[0] = '\0';
        extension = new char[1];
        extension[0] = '\0';
    }
    RegularFile(const RegularFile& other) : File(other) {
        copy(other);
    }
    RegularFile& operator=(const RegularFile& other) {
        if (this != &other) {
            File::operator=(other);
            erase();
            copy(other);
        }

        return *this;
    }
    ~RegularFile() {
        erase();
    }

    void printContent() const override {
        std::cout << name << "." << extension << "\n" << content;
    }
    File* operator+=(File* other) override {
        if (other->getFileType() == DIRECTORY) {
            return this;
        }
        if (other->getFileType() == LINK) {
            //TODO
        }
        strcat(content, dynamic_cast<RegularFile*>(other)->content);
        return this;
    }

    File* clone() const {
        return new RegularFile(*this);
    }

};