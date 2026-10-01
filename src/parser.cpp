#include "parser.hpp"

#include <cctype>

CommandType getCommandType(const std::string& name) {
    if (name == "SET") {
        return CommandType::SET;
    }

    if (name == "GET") {
        return CommandType::GET;
    }

    if (name == "DEL") {
        return CommandType::DEL;
    }

    if (name == "EXIT") {
        return CommandType::EXIT;
    }

    return CommandType::UNKNOWN;
}

Command parseCommand(const std::string& input) {
    Command command;

    command.type = CommandType::UNKNOWN;
    command.error = {ErrorType::NONE, ""};

    std::vector<std::string> tokens;
    std::string current;

    bool insideQuotes = false;

    for (char character : input) {
        if (character == '"') {
            insideQuotes = !insideQuotes;
            continue;
        }

        if (std::isspace(static_cast<unsigned char>(character)) &&
            !insideQuotes) {

            if (!current.empty()) {
                tokens.push_back(current);
                current.clear();
            }

        } else {
            current += character;
        }
    }

    if (insideQuotes) {
        command.error = {
            ErrorType::UNTERMINATED_QUOTE,
            "(error) unterminated quote"
        };

        return command;
    }

    if (!current.empty()) {
        tokens.push_back(current);
    }

    if (tokens.empty()) {
        command.error = {
            ErrorType::EMPTY_INPUT,
            "(error) empty command"
        };

        return command;
    }

    command.type = getCommandType(tokens[0]);

    for (std::size_t i = 1; i < tokens.size(); i++) {
        command.arguments.push_back(tokens[i]);
    }

    return command;
}