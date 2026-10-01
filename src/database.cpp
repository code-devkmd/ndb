#include "database.hpp"

void Database::set(const std::string& key, const std::string& value) {
    data[key] = value;
}

std::string Database::get(const std::string& key) {
    auto result = data.find(key);

    if (result != data.end()) {
        return result->second;
    }

    return "(nil)";
}

bool Database::del(const std::string& key) {
    return data.erase(key) > 0;
}