#ifndef EDGE_EXISTS_EXCEPTION_H
#define EDGE_EXISTS_EXCEPTION_H

#include <string>
/**
 * @file EdgeExistsException.hpp
 * @brief Custom exception for cases where an edge already exists in the graph.
 * @author galogimaymon@gmail.com
 */
class EdgeExistsException {
    std::string message;

public:
    EdgeExistsException(const std::string& msg) : message(msg) {}

    const char* what() const {
        return message.c_str();
    }
};

#endif
