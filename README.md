# cpp-book-library
A library book managment project



Core Features

Add new books (title, author, ISBN, number of copies)

Remove a book by its ISBNsd

Search for books by title or ISBN

Update book details if ISBN already exists

Display all books sorted alphabetically by title

Menu-driven dashboard for user interaction

C++ Concepts & STL Used

Classes and Objects for data abstraction

Access specifiers, constructors, and methods

STL containers: std::vector and std::map

STL algorithms: std::sort, std::find_if, std::remove_if

Formatted I/O using <iomanip>

Modular function design with conditionals and loops

Project Requirements

C++ compiler (g++, clang++, or an IDE)

C++17 or later for consistent STL behavior

Basic understanding of C++ classes, STL containers, and functions

Implementation Structure

Book Class: Stores title, author, ISBN, copies with getter/setter methods and a display function

Library Class: Manages vector<Book> collection with methods to add, remove, search (by title/ISBN), and display all books

Main Function: Provides a loop-based menu system for user interaction

Key Implementation Details

Adding a book checks for existing ISBN - updates if found, adds new book if not

Removing books uses remove_if algorithm followed by erase

Searching by title iterates through all books to find matches

Searching by ISBN uses find_if algorithm for exact matching

Display sorts books by title before showing them in a formatted table


