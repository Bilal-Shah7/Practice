#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

const int MAX_BOOKS = 100; // Maximum number of books

struct books {
    string title;
    int isbn;
    string author;
    string status;
};

void bubbleSort(books arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].isbn > arr[j + 1].isbn) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void searchISBN(books arr[], int n, int targetISBN) {
    // Bubble sort the array by ISBN
    bubbleSort(arr, n);

    // Perform a sequential search on the sorted array
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i].isbn == targetISBN) {
            cout << "Book found:\n";
            cout << "ISBN: " << arr[i].isbn << "\nTitle: " << arr[i].title
                 << "\nStatus: " << arr[i].status << "\nAuthor: " << arr[i].author << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Book with ISBN " << targetISBN << " not found.\n";
    }
}

void addBooks(books arr[], int &n) {
    cout << "Enter the number of books to add: ";
    int num;
    cin >> num;
    if (n + num > MAX_BOOKS) {
        cout << "Error: Exceeds maximum book limit.\n";
        return;
    }

    for (int i = n; i < n + num; i++) {
        cout << "Enter details for book " << i + 1 << ":\n";
        cout << "Enter ISBN: ";
        cin >> arr[i].isbn;
        cin.ignore();
        cout << "Enter Title: ";
        getline(cin, arr[i].title);
        cout << "Enter Status: ";
        getline(cin, arr[i].status);
        cout << "Enter Author: ";
        getline(cin, arr[i].author);
    }
    n += num;
}

void updateStatus(books arr[], int n, int targetISBN) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i].isbn == targetISBN) {
            cout << "Enter the updated status for the book: ";
            cin.ignore();
            getline(cin, arr[i].status);
            cout << "Status updated successfully.\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book with ISBN " << targetISBN << " not found.\n";
    }
}

void saveToFile(books arr[], int n) {
    ofstream outFile("Books.txt");
    if (!outFile) {
        cout << "Error opening file for writing.\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        outFile << arr[i].isbn << "," << arr[i].title << "," << arr[i].status << "," << arr[i].author << endl;
    }

    outFile.close();
    cout << "Book details saved to file successfully.\n";
}

void readFromFile(books arr[], int &n) {
    ifstream inFile("Books.txt");
    if (!inFile) {
        cout << "Error: Could not open file for reading.\n";
        return;
    }

    string line;
    while (getline(inFile, line) && n < MAX_BOOKS) {
        stringstream ss(line);
        string isbnStr;

        getline(ss, isbnStr, ',');
        arr[n].isbn = stoi(isbnStr);

        getline(ss, arr[n].title, ',');
        getline(ss, arr[n].status, ',');
        getline(ss, arr[n].author, ',');

        n++;
    }

    inFile.close();
    cout << "Books loaded successfully from file.\n";
}

int main() {
    books bookArr[MAX_BOOKS]; // Fixed-size array
    int numBooks = 0;         // Current number of books
    int choice;

    // Read books from file at the start
    readFromFile(bookArr, numBooks);

    while (true) {
        cout << "Menu:\n";
        cout << "1. Add Book details\n2. Update status of Book\n3. Search for a book using ISBN\n4. Save Book details to File\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBooks(bookArr, numBooks);
                break;
            case 2: {
                int isbn;
                cout << "Enter ISBN of the book to update: ";
                cin >> isbn;
                updateStatus(bookArr, numBooks, isbn);
                break;
            }
            case 3: {
                int isbn;
                cout << "Enter ISBN to search: ";
                cin >> isbn;
                searchISBN(bookArr, numBooks, isbn);
                break;
            }
            case 4:
                saveToFile(bookArr, numBooks);
                break;
            case 5:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
