#include <iostream>
#include <vector>
using namespace std;

class Book {
public:
    string title, author;
    int id;

    Book(int id, string title, string author) {
        this->id = id;
        this->title = title;
        this->author = author;
    }

    void display() {
        cout << "Book ID: " << id << "\nTitle: " << title << "\nAuthor: " << author << "\n\n";
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook() {
        int id;
        string title, author;

        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Book Title: ";
        getline(cin, title);
        cout << "Enter Author Name: ";
        getline(cin, author);

        books.push_back(Book(id, title, author));
        cout << "Book added successfully!\n";
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "Library is empty.\n";
            return;
        }
        cout << "--- Book List ---\n";
        for (Book b : books)
            b.display();
    }

    void searchBook() {
        string searchTitle;
        cin.ignore();
        cout << "Enter the title to search: ";
        getline(cin, searchTitle);

        bool found = false;
        for (Book b : books) {
            if (b.title == searchTitle) {
                cout << "Book found!\n";
                b.display();
                found = true;
                break;
            }
        }
        if (!found)
            cout << "Book not found!\n";
    }
};

int main() {
    Library lib;
    int choice;

    do {
        cout << "\n--- Library Menu ---\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            lib.addBook();
            break;
        case 2:
            lib.displayBooks();
            break;
        case 3:
            lib.searchBook();
            break;
        case 4:
            cout << "Exiting Library System...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
