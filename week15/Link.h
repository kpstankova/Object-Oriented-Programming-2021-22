#pragma once
#include "File.h"

class Link : public File {
private:
    File* const link;

public:
    Link(File* other) : link(other) {
        if (other->getFileType() == LINK) {
            delete link;
            throw "error";
        }
    }

    void printContent() const override {
        link->printContent();
    }

    File* operator+=(File* other) override {
        link->operator+=(other);
    }
};