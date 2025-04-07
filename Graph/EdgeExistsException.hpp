#ifndef EDGE_EXISTS_EXCEPTION_H
#define EDGE_EXISTS_EXCEPTION_H

#include <string>

class EdgeExistsException {
    std::string message;

public:
    EdgeExistsException(const std::string& msg) : message(msg) {}

    const char* what() const {
        return message.c_str();
    }
};

#endif