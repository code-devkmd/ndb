#include <cassert>
#include <iostream>

#include "../src/parser.hpp"

int main() {
    {
        Command command = parseCommand("SET name Nandeshore");

        assert(command.type == CommandType::SET);
        assert(command.arguments.size() == 2);
        assert(command.arguments[0] == "name");
        assert(command.arguments[1] == "Nandeshore");
        assert(command.error.type == ErrorType::NONE);
    }

    {
        Command command = parseCommand("GET name");

        assert(command.type == CommandType::GET);
        assert(command.arguments.size() == 1);
        assert(command.arguments[0] == "name");
    }

    {
        Command command = parseCommand("SET message \"Hello World\"");

        assert(command.type == CommandType::SET);
        assert(command.arguments.size() == 2);
        assert(command.arguments[1] == "Hello World");
    }

    {
        Command command = parseCommand("SET message \"Hello World");

        assert(command.error.type == ErrorType::UNTERMINATED_QUOTE);
    }

    {
        Command command = parseCommand("");

        assert(command.error.type == ErrorType::EMPTY_INPUT);
    }

    {
        Command command = parseCommand("HELLO");

        assert(command.type == CommandType::UNKNOWN);
    }

    std::cout << "All parser tests passed!\n";

    return 0;
}