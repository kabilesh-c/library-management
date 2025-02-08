```
# Library Management System
A command-line based library management system written in C that allows users to manage books, members, and lending operations.

## Features
- Add and remove books from the library
- Register new members
- Issue books to members
- Return books
- Search books by title or author
- Display all available books
- Save/load library data to/from files

## Project Structure
```
library-management/
├── src/
│   ├── main.c
│   ├── book.c
│   ├── book.h
│   ├── member.c
│   ├── member.h
│   ├── filehandler.c
│   ├── filehandler.h
│   └── utils.c
├── data/
│   ├── books.dat
│   └── members.dat
├── Makefile
├── README.md
└── .gitignore
```

## Prerequisites
- GCC Compiler
- Make (optional, for using Makefile)

## Installation
1. Clone the repository:
```bash
git clone https://github.com/yourusername/library-management.git
cd library-management
```

2. Compile the project:
```bash
make
```
Or manually compile:
```bash
gcc src/*.c -o library
```

3. Run the program:
```bash
./library
```

## Usage
The program provides a menu-driven interface:
1. Add New Book
2. Remove Book
3. Search Books
4. Display All Books
5. Add New Member
6. Issue Book
7. Return Book
8. Exit

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License
[MIT](https://choosealicense.com/licenses/mit/)
```