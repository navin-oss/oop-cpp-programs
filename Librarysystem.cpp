#include <iostream>
#include <vector>
using namespace std;

class Book {
private:
    string title;
    string author;
    int pageCount;
   
public:
    Book(string t = "Shama chi Aai", string a = "sane guruji", int p = 450, bool format = false) {
        title = t;
        author = a;
        pageCount = p;
      
    }

    void display() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Pages: " << pageCount << endl;
        
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(const Book& b) {
        books.push_back(b);
    }

    void displayAllBooks() {
        for (size_t i = 0; i < books.size(); ++i) {
            books[i].display();
            cout << "--------------------------------------------------------------------------- " << endl;
        }
    }
};

int main() {
    Library library;


    Book book1;
    library.addBook(book1);

    
    Book book2("yayati", "V.S.Khandekar", 208, true);
    library.addBook(book2);
    Book book3("The Indian War of Independance", "V.D.Savarkar",474, true);
    library.addBook(book3);
    cout << "Library Records:" << endl;
    library.displayAllBooks();

    return 0;
}

hello navin

