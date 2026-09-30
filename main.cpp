#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

class Database {
private:
    unordered_map<string, string> data;

public:
    void set(string key, string value) {
        data[key] = value;
    }

    string get(string key) {
        auto result = data.find(key);

        if (result != data.end()) {
            return result->second;
        }

        return "(nil)";
    }

    bool del(string key) {
        return data.erase(key) > 0;
    }
};

int main() {
    Database db;

    cout << "NDB v0.1\n";

    while (true) {
        cout << "> ";

        string input;
        getline(cin, input);

        stringstream ss(input);

        string command;
        string key;
        string value;

        ss >> command >> key >> value;

        if (command == "SET") {
            db.set(key, value);
            cout << "OK\n";
        }
        else if (command == "GET") {
            cout << db.get(key) << "\n";
        }
        else if (command == "DEL") {
            if (db.del(key)) {
                cout << "OK\n";
            } else {
                cout << "(nil)\n";
            }
        }
        else if (command == "EXIT") {
            break;
        }
    }

    return 0;
}