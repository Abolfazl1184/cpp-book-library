#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Book{
    private: 

    string title;
    string author;
    string isbn;
    int copies;

    public: 

    // Constructor to initialize book data
    Book(string t, string a, string i, int c) 
        : title (t), author (a), isbn (i), copies (c) {}

       // Getter methods to access book details
       string getTitle() const {return title;}
       string getAuthor() const {return author;}
       string getIsbn () const {return isbn;}
       int getCopies () const {return copies;} 

       // Setter methods to update book details
       void setTitle (std::string t) {title = t;}
       void setAuthor (std::string a) {author = a;}
       void setCopies (int c) {copies = c;}
       
       // Display book details in a formatted way
       void display() const 
       {
        cout << left << setw(25) << title
                     << setw(20) << author 
                     << setw(15) << isbn
                     << setw(10) << copies
                     << "\n";          
       }
};

vector<Book> books;

void addBook(const Book& book)
{
    auto it = find_if(books.begin(), books.end(), [&]( Book& b) {
         return b.getIsbn() == book.getIsbn();   
     });
 


if (it != books.end())
{
   cout << "Book with same ISBN exists. Updating details.\n";
   it -> setTitle (book.getTitle());
   it -> setAuthor (book.getAuthor());
   it -> setCopies (book.getCopies());
}
   else
   {
    books.push_back(book);
    cout << "Book added successfully.\n";
   }


}

void removeBook (const string& isbn)
{
    auto it = remove_if ( books.begin(), books.end(), [&](Book& b) {
         return b.getIsbn() == isbn;
    });

if (it != books.end())
{  
   books.erase(it, books.end());
   cout << "Book removed succesfully.\n"; 
}
   else
   {
    cout << "No book found with that ISBN.\n";
   }
}

int main() {
    cout << "=== LIBRARY MANAGEMENT SYSTEM ===\n\n";
    
    // ===== تست 1: اضافه کردن کتاب‌های جدید =====
    cout << "--- Test 1: Adding New Books ---\n";
    
    Book book1("C++ Programming", "Bjarne Stroustrup", "978-0321563842", 5);
    addBook(book1);
    
    Book book2("Clean Code", "Robert C. Martin", "978-0132350884", 3);
    addBook(book2);
    
    Book book3("Design Patterns", "Erich Gamma", "978-0201633610", 2);
    addBook(book3);
    
    Book book4("The Pragmatic Programmer", "David Thomas", "978-0201616224", 4);
    addBook(book4);
    
    // ===== تست 2: نمایش همه کتاب‌ها =====
    cout << "\n--- Test 2: Displaying All Books ---\n";
    cout << left << setw(25) << "Title" 
         << setw(20) << "Author" 
         << setw(15) << "ISBN" 
         << setw(10) << "Copies" << "\n";
    cout << string(70, '-') << "\n";
    
    for (const auto& book : books) {
        book.display();
    }
    cout << "\nTotal books in library: " << books.size() << "\n";
    
    // ===== تست 3: اضافه کردن کتاب تکراری (با ISBN تکراری) =====
    cout << "\n--- Test 3: Adding Duplicate Book (Same ISBN) ---\n";
    Book book5("C++ Programming - Updated", "B. Stroustrup", "978-0321563842", 10);
    addBook(book5);
    
    // نمایش بعد از آپدیت
    cout << "\nAfter update:\n";
    cout << left << setw(25) << "Title" 
         << setw(20) << "Author" 
         << setw(15) << "ISBN" 
         << setw(10) << "Copies" << "\n";
    cout << string(70, '-') << "\n";
    for (const auto& book : books) {
        book.display();
    }
    
    // ===== تست 4: حذف یک کتاب =====
    cout << "\n--- Test 4: Removing a Book ---\n";
    cout << "Removing book with ISBN: 978-0132350884\n";
    removeBook("978-0132350884");
    
    // نمایش بعد از حذف
    cout << "\nAfter removal:\n";
    cout << left << setw(25) << "Title" 
         << setw(20) << "Author" 
         << setw(15) << "ISBN" 
         << setw(10) << "Copies" << "\n";
    cout << string(70, '-') << "\n";
    for (const auto& book : books) {
        book.display();
    }
    cout << "\nTotal books: " << books.size() << "\n";
    
    // ===== تست 5: حذف کتابی که وجود ندارد =====
    cout << "\n--- Test 5: Removing Non-existent Book ---\n";
    cout << "Trying to remove ISBN: 999-9999999999\n";
    removeBook("999-9999999999");
    
    // ===== تست 6: نمایش نهایی کتاب‌ها =====
    cout << "\n--- Test 6: Final Library Status ---\n";
    if (books.empty()) {
        cout << "Library is empty!\n";
    } else {
        cout << left << setw(25) << "Title" 
             << setw(20) << "Author" 
             << setw(15) << "ISBN" 
             << setw(10) << "Copies" << "\n";
        cout << string(70, '-') << "\n";
        for (const auto& book : books) {
            book.display();
        }
        cout << "\nTotal books: " << books.size() << "\n";
    }
    
    cout << "\n=== Program Finished ===\n";
    
    return 0;
}
