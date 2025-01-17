#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct books
{
    string title;
    int isbn;
    string author;
    string status;
};

void updatestatus(books *book, int ibn, int nobooks)
{
    string line;
    fstream myfile, updatedfile;
    myfile.open("Books.txt", fstream::in);
    updatedfile.open("temp.txt", fstream ::out);
    string updatedstatus;
    cout << "Enter updated status of the Book : ";
    cin >> updatedstatus;
    bool found = false;
    if (!myfile.is_open() || !updatedfile.is_open())
        cout << "Error opening the file.";

    else
    {
        while (!myfile.eof())
        {
            while (getline(myfile, line))
            {
                stringstream sd(line);
                string isbnn, title, status, author;
                getline(sd, isbnn, ',');
                getline(sd, title, ',');
                getline(sd, status, ',');
                getline(sd, author, ',');

                if (line.find(ibn) == 0)
                {
                    updatedfile << isbnn << ", " << title << ", " << updatedstatus << ", " << author << endl;
                    found = true;
                }
                else
                {
                    updatedfile << isbnn << ", " << title << ", " << status << ", " << author << endl;
                }
            }
        }
    }
    myfile.close();
    updatedfile.close();
    remove("Books.txt");
    rename("temp.txt", "Books.txt");
    if (!found)
    {
        cout << "book not found";
    }
}

void search(books *book)
{
    int ibn;
    string data;
    cout << "Enter ISBN of the book you are looking for : ";
    cin >> ibn;
    fstream myfile;
    myfile.open("Books.txt", fstream::in);
    if (!myfile)
        cout << "Error";
    else
    {
        while (!myfile.eof())
        {
            while (getline(myfile, data))
            {
                if (data.find(ibn + ",") == 0)
                {
                    cout << data;
                    break;
                }
            }
        }
    }
};

void addtofile(books *book, int nobooks)
{
    fstream myfile;
    myfile.open("Books.txt", fstream::out);
    if (!myfile)
        cout << "Error" << endl;
    else
    {
        for (int i = 0; i < nobooks; i++)
        {
            myfile << book[i].isbn << ", " << book[i].title << ", " << book[i].status << ", " << book[i].author << endl;
        }
        cout << "data added." << endl;
    }
}
int main()
{
    int choice;
    books *book = nullptr;
    int nobooks = 0;
    int ibn;
    while (true)
    {

        cout << "Menu"<<endl;
        cout << "1. Add Book details.\n2. Update status of Book.\n3. Search for a book using ISBN.\n4. Save Book details to the File.\n5. Exit menu.\n";
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {

        case 1:
        {
            cout << "Enter No. of Books you want to add : ";
            cin >> nobooks;
            book = new books[nobooks];
            for (int i = 0; i < nobooks; i++)
            {
                cout << "Enter details of Book " << i + 1 << ".\n";
                cout << "Enter ISBN of Book : ";
                cin >> book[i].isbn;
                cin.ignore();
                cout << "Enter Title of Book : ";
                getline(cin, book[i].title);
                cout << "Enter Status of Book : ";
                getline(cin, book[i].status);
                cout << "Enter Author Name of Book : ";
                getline(cin, book[i].author);
            }
            break;
        }

        case 2:
        {
            cout << "Enter ISBN of Book";
            cin >> ibn;
            updatestatus(book, ibn, nobooks);
            break;
        }
        case 3:
        {
            search(book);
            break;
        }
        case 4:
        {
            addtofile(book, nobooks);
            break;
        }
        case 5:
            cout << "exiting program..";
            delete[] book;
            return 0;
        }
    }
}