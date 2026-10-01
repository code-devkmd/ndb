#pragma once

#include <string>

enum class ErrorType {
    NONE,
    EMPTY_INPUT,
    UNKNOWN_COMMAND,
    WRONG_ARGUMENT_COUNT,
    UNTERMINATED_QUOTE
};

struct Error {
    ErrorType type;
    std::string message;
};