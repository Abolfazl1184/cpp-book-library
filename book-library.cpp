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

void searchByTitle (const string& title)
{
    bool found = false;
    for ( auto& b : books)
    {
        if( b.getTitle()==title)
        {
            b.display();
            found = true;
        }
    }
    if (!found)
        cout << "No book found witch that title.\n";
}
int main() {
    cout << "\n========================================\n";
    cout << "       LIBRARY MANAGEMENT SYSTEM\n";
    cout << "========================================\n\n";
    
    // ===== بخش 1: اضافه کردن کتاب =====
    cout << "📚 PART 1: ADDING BOOKS\n";
    cout << "----------------------------------------\n";
    addBook(Book("C++ Programming", "Bjarne Stroustrup", "978-111", 5));
    addBook(Book("Clean Code", "Robert Martin", "978-222", 3));
    addBook(Book("Design Patterns", "Erich Gamma", "978-333", 2));
    addBook(Book("The Pragmatic Programmer", "David Thomas", "978-444", 4));
    
    // ===== بخش 2: نمایش همه کتاب‌ها =====
    cout << "\n📚 PART 2: DISPLAY ALL BOOKS\n";
    cout << "----------------------------------------\n";
    cout << left << setw(25) << "Title"
         << setw(20) << "Author"
         << setw(15) << "ISBN"
         << setw(10) << "Copies" << "\n";
    cout << string(70, '-') << "\n";
    for (const auto& book : books) {
        book.display();
    }
    cout << "\nTotal books: " << books.size() << "\n";
    
    // ===== بخش 3: جستجوی کتاب با عنوان =====
    cout << "\n🔍 PART 3: SEARCH BOOKS BY TITLE\n";
    cout << "----------------------------------------\n";
    cout << "Searching for 'C++ Programming':\n";
    searchByTitle("C++ Programming");
    
    cout << "\nSearching for 'Python Programming':\n";
    searchByTitle("Python Programming");
    
    // ===== بخش 4: اضافه کردن کتاب تکراری =====
    cout << "\n📚 PART 4: ADD DUPLICATE BOOK (SAME ISBN)\n";
    cout << "----------------------------------------\n";
    addBook(Book("C++ Programming - Updated", "B. Stroustrup", "978-111", 10));
    
    // ===== بخش 5: نمایش بعد از آپدیت =====
    cout << "\n📚 PART 5: DISPLAY AFTER UPDATE\n";
    cout << "----------------------------------------\n";
    cout << left << setw(25) << "Title"
         << setw(20) << "Author"
         << setw(15) << "ISBN"
         << setw(10) << "Copies" << "\n";
    cout << string(70, '-') << "\n";
    for (const auto& book : books) {
        book.display();
    }
    cout << "\nTotal books: " << books.size() << "\n";
    
    // ===== بخش 6: حذف کتاب =====
    cout << "\n🗑️  PART 6: REMOVE BOOK BY ISBN\n";
    cout << "----------------------------------------\n";
    cout << "Removing book with ISBN 978-222:\n";
    removeBook("978-222");
    
    // ===== بخش 7: نمایش بعد از حذف =====
    cout << "\n📚 PART 7: DISPLAY AFTER REMOVAL\n";
    cout << "----------------------------------------\n";
    cout << left << setw(25) << "Title"
         << setw(20) << "Author"
         << setw(15) << "ISBN"
         << setw(10) << "Copies" << "\n";
    cout << string(70, '-') << "\n";
    for (const auto& book : books) {
        book.display();
    }
    cout << "\nTotal books: " << books.size() << "\n";
    
    // ===== بخش 8: حذف کتاب ناموجود =====
    cout << "\n🗑️  PART 8: TRY TO REMOVE NON-EXISTENT BOOK\n";
    cout << "----------------------------------------\n";
    cout << "Trying to remove ISBN 999-999:\n";
    removeBook("999-999");
    
    // ===== بخش 9: جستجوی دوباره =====
    cout << "\n🔍 PART 9: SEARCH AGAIN AFTER CHANGES\n";
    cout << "----------------------------------------\n";
    cout << "Searching for 'C++ Programming':\n";
    searchByTitle("C++ Programming");
    
    // ===== بخش 10: نمایش نهایی =====
    cout << "\n📊 PART 10: FINAL SUMMARY\n";
    cout << "----------------------------------------\n";
    cout << "Total books in library: " << books.size() << "\n";
    if (!books.empty()) {
        cout << "\nRemaining books:\n";
        cout << left << setw(25) << "Title"
             << setw(20) << "Author"
             << setw(15) << "ISBN"
             << setw(10) << "Copies" << "\n";
        cout << string(70, '-') << "\n";
        for (const auto& book : books) {
            book.display();
        }
    }
    
    cout << "\n========================================\n";
    cout << "       PROGRAM FINISHED SUCCESSFULLY!\n";
    cout << "========================================\n";
    
    return 0;
}
