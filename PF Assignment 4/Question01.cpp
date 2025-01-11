#include <iostream>
#include <fstream>
using namespace std;

struct student
{
    string name;
    int rollNo;
    int marks[5];
    int total;
    int average;
};

void calculate(student *students, int noofstds)
{
    for (int i = 0; i < noofstds; ++i)
    {
        students[i].total = 0;

        for (int j = 0; j < 5; ++j)
        {
            students[i].total += students[i].marks[j];
        }

        students[i].average = students[i].total / 5.0;
    }
};

void display(student *students, int noofstds)
{

    cout << "Roll No\tName\t\ttotal Marks\taverage" << endl;
    cout << "--------------------------------------\n";
    for (int i = 0; i < noofstds; i++)
    {
        cout << students[i].rollNo << "\t" << students[i].name << "\t\t" << students[i].total << "\t" << students[i].average << endl;
    }
};

void savedata(student *students, int noofstds)
{
    ofstream myfile;
    myfile.open("Students.txt");
    if (!myfile.is_open())
    {
        cout << "Error opening the file";
        return;
    }
    else
    {
        for (int i = 0; i < noofstds; i++)
        {
            myfile << students[i].rollNo << " " << students[i].name << " " << students[i].total << " " << students[i].average << "\n";
        }
        myfile.close();
        cout << "Data saved to the file successfully.";
    };
}
void readdata(student *students, int noofstds)
{
    ifstream myfile;
    myfile.open("Students.txt");
    if (!myfile.is_open())
    {
        cout << "Error opening the file";
        return;
    }
    else
    {
        for (int i = 0; i < noofstds; i++)
        {
            myfile >> students[i].rollNo;
            myfile >> students[i].name;
            myfile >> students[i].total;
            myfile >> students[i].average;
        }
        myfile.close();
    }
};

int main()
{

    int noofstds = 0;
    student *students = nullptr;
    int choice;
    while (true)
    {

        cout << "MENU\n";
        cout << "1. Add new Student Data." << endl;
        cout << "2. Display Student Data." << endl;
        cout << "3. Add student data to a file." << endl;
        cout << "4. display data from file." << endl;
        cout << "5. Exit." << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter No of students : ";
            cin >> noofstds;
            cin.ignore();
            students = new student[noofstds];
            for (int i = 0; i < noofstds; i++)
            {
                cout << "Enter details of student " << i + 1 << ": \n";
                
                cout << "Enter Roll No. of student : ";
                cin >> students[i].rollNo;
                cin.ignore();
                cout << "Enter Name of student : ";
                getline(cin, students[i].name);

                for (int j = 0; j < 5; j++)
                {
                    cout << "Enter Marks of the subject " << j + 1 << " : ";
                    cin >> students[i].marks[j];
                }
            }
            calculate(students, noofstds);
            break;
        }

        case 2:
        {
            if (students != nullptr)
            {
                display(students, noofstds);
            }
            else
            {
                cout << "No data to display";
            }
            break;
        }
        case 3:
        {
            if (students != nullptr)
            {
                savedata(students, noofstds);
            }
            else
            {
                cout << "No data to add";
            }
            break;
        }
        case 4:
        {
            readdata(students, noofstds);
            break;
        }
        case 5:
        {
            delete[] students;
            cout << "Exiting program";
            return 0;
        }
        default:
        {
            cout << "Invalid Choice" << endl;
        }
        }
    }
}