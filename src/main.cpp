#include <iostream>
#include <string>

#include "database.hpp"
#include "parser.hpp"

Error validateCommand(const Command& command) {
    if (command.error.type != ErrorType::NONE) {
        return command.error;
    }

    if (command.type == CommandType::UNKNOWN) {
        return {
            ErrorType::UNKNOWN_COMMAND,
            "(error) unknown command"
        };
    }

    if (command.type == CommandType::SET &&
        command.arguments.size() != 2) {
        return {
            ErrorType::WRONG_ARGUMENT_COUNT,
            "(error) SET requires 2 arguments"
        };
    }

    if ((command.type == CommandType::GET ||
         command.type == CommandType::DEL) &&
        command.arguments.size() != 1) {
        return {
            ErrorType::WRONG_ARGUMENT_COUNT,
            "(error) command requires 1 argument"
        };
    }

    if (command.type == CommandType::EXIT &&
        !command.arguments.empty()) {
        return {
            ErrorType::WRONG_ARGUMENT_COUNT,
            "(error) EXIT requires 0 arguments"
        };
    }

    return {
        ErrorType::NONE,
        ""
    };
}

int main() {
    Database db;

    std::cout << "NDB v0.6\n";

    while (true) {
        std::cout << "> ";

        std::string input;
        std::getline(std::cin, input);

        Command command = parseCommand(input);

        Error error = validateCommand(command);

        if (error.type != ErrorType::NONE) {
            std::cout << error.message << "\n";
            continue;
        }

        switch (command.type) {
            case CommandType::SET:
                db.set(
                    command.arguments[0],
                    command.arguments[1]
                );

                std::cout << "OK\n";
                break;

            case CommandType::GET:
                std::cout << db.get(command.arguments[0]) << "\n";
                break;

            case CommandType::DEL:
                if (db.del(command.arguments[0])) {
                    std::cout << "OK\n";
                } else {
                    std::cout << "(nil)\n";
                }
                break;

            case CommandType::EXIT:
                return 0;

            case CommandType::UNKNOWN:
                break;
        }
    }
}