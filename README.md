# NDB

**NDB** — a Redis-inspired in-memory key-value database written from scratch in modern C++.

NDB is a learning project focused on understanding how databases work internally by building one from the ground up, starting with a simple in-memory key-value store.

## v0.1

The first milestone implements a minimal database with three operations:

* `SET` — store a key-value pair
* `GET` — retrieve a value
* `DEL` — delete a key-value pair
* `EXIT` — exit the database

### Example

```text
NDB v0.1
> SET name Alex
OK
> GET name
Alex
> GET unknown
(nil)
> DEL name
OK
> GET name
(nil)
> EXIT
```

## How It Works

NDB currently uses C++'s `std::unordered_map` as its in-memory storage:

```text
key → value

"name"     → "Alex"
"city"     → "Imphal"
"language" → "C++"
```

The database is wrapped inside a `Database` class that exposes simple operations:

```cpp
db.set("name", "Alex");
db.get("name");
db.del("name");
```

There is currently no persistence, networking, custom storage engine, or external database dependency.

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
g++ main.cpp -o ndb
```

Run:

```bash
./ndb
```

## Roadmap

NDB will evolve incrementally from a simple in-memory database into a more complete database system.

### v0.1 — Basic Key-Value Store

* [x] `SET`
* [x] `GET`
* [x] `DEL`
* [x] Interactive CLI
* [x] In-memory storage

### Future

* [ ] Better command parsing
* [ ] Error handling
* [ ] Multiple data types
* [ ] Persistence
* [ ] Custom hash table
* [ ] Database file format
* [ ] Tests
* [ ] CMake build system
* [ ] Networking
* [ ] Client/server architecture
* [ ] Performance improvements

The roadmap may change as the project develops.

## Project Structure

```text
ndb/
├── main.cpp
├── README.md
├── .gitignore
└── LICENSE
```

The project intentionally starts with a minimal structure. More files and directories will be introduced when the codebase actually needs them.

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

Rather than starting with a large framework, NDB is being built incrementally from basic C++.

## Status

**Current version: v0.1**

NDB is an early-stage experimental project and is not intended for production use.
