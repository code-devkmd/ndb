# NDB

**NDB** — a Redis-inspired in-memory key-value database written from scratch in modern C++.

NDB is a learning project focused on understanding how databases work internally by building one from the ground up.

The project starts with a simple in-memory key-value store and evolves incrementally toward a more complete database system.

## Current Version

**v0.6**

NDB currently supports:

* `SET` — store a key-value pair
* `GET` — retrieve a value
* `DEL` — delete a key-value pair
* `EXIT` — exit the database
* Quoted values
* Command validation
* Parser error handling
* Automated parser tests

## Example

```text
NDB v0.6

> SET name Nandeshore
OK

> GET name
Nandeshore

> SET message "Hello World"
OK

> GET message
Hello World

> DEL name
OK

> GET name
(nil)

> EXIT
```

## How It Works

NDB currently uses C++'s `std::unordered_map` as its in-memory storage:

```text
key        → value

"name"     → "Nandeshore"
"city"     → "Imphal"
"language" → "C++"
```

The database is encapsulated inside a `Database` class:

```cpp
db.set("name", "Nandeshore");

db.get("name");

db.del("name");
```

Commands are processed through a separate parser before reaching the database:

```text
User input
    ↓
Parser
    ↓
Command
    ↓
Validation
    ↓
Database
    ↓
unordered_map
```

NDB currently has no persistence, networking, custom storage engine, or external database dependency.

## Requirements

* C++ compiler with C++11 or newer
* Linux, macOS, or Windows

## Build

Clone the repository:

```bash
git clone https://github.com/code-devkmd/ndb.git
cd ndb
```

Compile:

```bash
g++ src/main.cpp src/database.cpp src/parser.cpp -o ndb
```

Run:

```bash
./ndb
```

## Running Tests

NDB includes automated parser tests.

Compile the tests:

```bash
g++ tests/test_parser.cpp src/parser.cpp -o test_parser
```

Run:

```bash
./test_parser
```

Expected output:

```text
All parser tests passed!
```

## Roadmap

NDB is being developed incrementally, with each version introducing a specific part of the database system.

### v0.1 — Basic Key-Value Store

* [x] `SET`
* [x] `GET`
* [x] `DEL`
* [x] Interactive CLI
* [x] In-memory storage

### v0.2 — Database Separation

* [x] Separate database header
* [x] Separate database implementation
* [x] Basic project structure

### v0.3 — Command Parser

* [x] Command parser
* [x] Command arguments
* [x] Separate parser module

### v0.4 — Typed Commands & Errors

* [x] `CommandType` enum
* [x] Command validation
* [x] Structured error types

### v0.5 — Tokenizer

* [x] Tokenization
* [x] Quoted values
* [x] Multi-word values

### v0.6 — Parser Tests & Error Handling

* [x] Parser errors
* [x] Unterminated quote detection
* [x] Automated parser tests

### Future

* [ ] Database tests
* [ ] Improved command system
* [ ] CMake build system
* [ ] Multiple data types
* [ ] Custom hash table
* [ ] Persistence
* [ ] Database file format
* [ ] Serialization
* [ ] Networking
* [ ] Client/server architecture
* [ ] Performance improvements

The roadmap may change as the project develops.

## Project Structure

```text
ndb/
├── src/
│   ├── main.cpp
│   ├── database.cpp
│   ├── database.hpp
│   ├── parser.cpp
│   ├── parser.hpp
│   └── error.hpp
├── tests/
│   └── test_parser.cpp
├── README.md
├── .gitignore
└── LICENSE
```

The project started with a minimal structure and is being expanded as new functionality requires additional modules.

## Why NDB?

NDB is primarily a systems-programming and learning project.

The goal is to understand concepts such as:

* Data structures
* Hash tables
* Memory management
* File persistence
* Serialization
* Networking
* Client/server architecture
* Database internals
* C++ design
* Software architecture
* Automated testing

Rather than starting with a large framework or relying on an existing database engine, NDB is being built incrementally from basic C++.

## Status

**Current version: v0.6**

NDB is an early-stage experimental project and is not intended for production use.
