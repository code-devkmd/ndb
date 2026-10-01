#pragma once

#include <string>
#include <vector>

#include "error.hpp"

enum class CommandType {
    SET,
    GET,
    DEL,
    EXIT,
    UNKNOWN
};

struct Command {
    CommandType type;
    std::vector<std::string> arguments;
    Error error;
};

Command parseCommand(const std::string& input);