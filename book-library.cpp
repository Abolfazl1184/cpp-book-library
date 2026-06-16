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

void searchByIsbn (const string& isbn)
{
    auto it = find_if ( books.begin(), books.end(), [&](Book& b) {
         return b.getIsbn() == isbn;
    });
    if (it != books.end())
       it -> display();

    else
        cout << "No book found with that ISBN.\n";
}   

void displayBook() 
{
    if (books.empty())
    {
        cout << "Library is empty.\n";
        return;
    }     

sort (books.begin(), books.end(), [](Book& a , Book& b) {
     return a.getTitle() < b.getTitle();
});
    
     cout << left << setw(25) << "Title"
                  << setw(20) << "Author"
                  << setw(15) << "Isbn"
                  << setw(10) << "Copies" << "\n";
    cout << string(70, '-') << "\n";

    for(const auto& b : books)
    {
        b.display();
    }
}
int main() {
    cout << "\n========================================\n";
    cout << "     LIBRARY MANAGEMENT SYSTEM\n";
    cout << "========================================\n\n";

    // ===== تست 1: اضافه کردن کتاب =====
    cout << "📚 TEST 1: ADDING BOOKS\n";
    cout << "----------------------------------------\n";
    addBook(Book("Design Patterns", "Erich Gamma", "333", 2));
    addBook(Book("Clean Code", "Robert Martin", "222", 3));
    addBook(Book("C++ Programming", "Bjarne Stroustrup", "111", 5));
    addBook(Book("The Pragmatic Programmer", "David Thomas", "444", 4));

    // ===== تست 2: نمایش کتاب‌ها (مرتب شده) =====
    cout << "\n📚 TEST 2: DISPLAY BOOKS (SORTED BY TITLE)\n";
    cout << "----------------------------------------\n";
    displayBook();

    // ===== تست 3: جستجو بر اساس عنوان =====
    cout << "\n🔍 TEST 3: SEARCH BY TITLE\n";
    cout << "----------------------------------------\n";
    cout << "Searching for 'C++ Programming':\n";
    searchByTitle("C++ Programming");
    
    cout << "\nSearching for 'Python':\n";
    searchByTitle("Python");

    // ===== تست 4: جستجو بر اساس ISBN =====
    cout << "\n🔍 TEST 4: SEARCH BY ISBN\n";
    cout << "----------------------------------------\n";
    cout << "Searching for ISBN '222':\n";
    searchByIsbn("222");
    
    cout << "\nSearching for ISBN '999':\n";
    searchByIsbn("999");

    // ===== تست 5: اضافه کردن کتاب تکراری =====
    cout << "\n📚 TEST 5: ADD DUPLICATE BOOK (SAME ISBN)\n";
    cout << "----------------------------------------\n";
    addBook(Book("C++ Programming - Updated", "B. Stroustrup", "111", 10));

    // ===== تست 6: نمایش بعد از آپدیت =====
    cout << "\n📚 TEST 6: DISPLAY AFTER UPDATE\n";
    cout << "----------------------------------------\n";
    displayBook();

    // ===== تست 7: حذف کتاب =====
    cout << "\n🗑️ TEST 7: REMOVE BOOK BY ISBN\n";
    cout << "----------------------------------------\n";
    cout << "Removing ISBN '222':\n";
    removeBook("222");

    // ===== تست 8: نمایش بعد از حذف =====
    cout << "\n📚 TEST 8: DISPLAY AFTER REMOVAL\n";
    cout << "----------------------------------------\n";
    displayBook();

    // ===== تست 9: حذف کتاب ناموجود =====
    cout << "\n🗑️ TEST 9: REMOVE NON-EXISTENT BOOK\n";
    cout << "----------------------------------------\n";
    cout << "Trying to remove ISBN '999':\n";
    removeBook("999");

    // ===== تست 10: جستجوی دوباره =====
    cout << "\n🔍 TEST 10: SEARCH AGAIN AFTER CHANGES\n";
    cout << "----------------------------------------\n";
    cout << "Searching for 'C++ Programming':\n";
    searchByTitle("C++ Programming");

    // ===== تست 11: نمایش نهایی =====
    cout << "\n📊 TEST 11: FINAL SUMMARY\n";
    cout << "----------------------------------------\n";
    cout << "Total books in library: " << books.size() << "\n";
    displayBook();

    cout << "\n========================================\n";
    cout << "     PROGRAM FINISHED SUCCESSFULLY!\n";
    cout << "========================================\n";

    return 0;
}