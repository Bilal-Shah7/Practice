#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void newemployee()
{
    fstream myfile;
    myfile.open("Data.txt", fstream ::app);

    string id, name, department;
    double salary;

    cout << "Enter ID of the Employee : ";
    cin >> id;
    cin.ignore();
    cout << "Enter Full Name of the Employee : ";
    getline(cin, name);
    cout << "Enter Department Name of the Employee : ";
    getline(cin, department);
    cout << "Enter Salary of the Employee : ";
    cin >> salary;

    myfile << "\n" << id << ", " << name << ", " << department << ", " << salary;

    myfile.close();
    cout << "Data added successfully";
}

void display()
{
    fstream myfile;
    myfile.open("Data.txt", fstream ::in);
    string display;
    cout << "Records of All Employees" << endl;
    while (!myfile.eof())
    {
        getline(myfile, display);
        cout << display << endl;
    }

    myfile.close();
}

void search()
{
    fstream myfile;
    myfile.open("Data.txt", fstream ::in);
    if (!myfile.is_open())
    {
        cout << "Error Opening the file" << endl;
    }
    else
    {
        string id, data;
        cout << "Enter ID of the Employee : ";
        cin >> id;

        bool found = false;
        while (!myfile.eof())
        {
            while (getline(myfile, data))
            {
                if (data.find(id + ",") == 0)
                {
                    cout << "Record found" << endl;
                    cout << "Employee Record is : " << data;
                    found = true;
                    break;
                }
            }
            if (found == false)
            {
                cout << "Record not found" << endl;
                break;
            }
        }
    }
}

void update()
{
    string id, line;
    string updatedslry;
    fstream myfile;
    fstream tempfile;
    myfile.open("Data.txt", fstream ::in);
    tempfile.open("temp.txt", fstream ::out);
    if (!myfile.is_open() || !tempfile.is_open())
    {
        cout << "Error";
    }

    cout << "Enter Employee ID : ";
    cin >> id;
    cout << "Enter his/her New Salary : ";
    cin >> updatedslry;

    bool found = false;
    while (!myfile.eof())
    {
        while (getline(myfile, line))
        {

            stringstream sd(line);
            string idd, fullname, department, salary;
            getline(sd, idd, ',');
            getline(sd, fullname, ',');
            getline(sd, department, ',');
            getline(sd, salary, ',');

            if (line.find(id + ",") == 0)
            {
                tempfile << idd << "," << fullname << "," << department << ", " << updatedslry << endl;

                found = true;
            }
            else
            {
                tempfile << line << endl;
            }
        }
        myfile.close();
        tempfile.close();

        remove("Data.txt");
        rename("temp.txt", "Data.txt");

        if (found)
        {
            cout << "Salary updated" << endl;
        }
        else
        {
            cout << "No Employee with the ID : " << id << ",  is found." << endl;
        }
    }
}

void deletee()
{
    fstream myfile;
    fstream tempfile;
    myfile.open("Data.txt", fstream ::in);
    tempfile.open("temp.txt", fstream ::out);

    if (!myfile.is_open() || !tempfile.is_open())
    {
        cout << "Error opening the file" << endl;
    }
    string id;
    cout << "\nEnter ID of the Employee : ";
    cin >> id;
    string line;
    bool found = false;
    while (!myfile.eof())
    {

        while (getline(myfile, line))
        {
            if (line.find(id + ",") == 0)
            {
                cout << line << "\nData of the Employee with the above records is deleted." << endl;
                found = true;
                continue;
            }
            else
            {
                tempfile << line << endl;
            }
        }

        myfile.close();
        tempfile.close();

        remove("Data.txt");
        rename("temp.txt", "Data.txt");

        if (found)
        {
            cout << "Data Deleted Successfully.";
        }
        if (!found)
        {
            cout << "No Employee with such ID : " << id << ", is registered.";
        }
    }
};

int main()
{
    int a;

    cout << "Hello Sir! How can we help you ? \n\nKindly Select One " << endl;
    cout << "\n1. Add New Employee details. \n2. Display All Employees Records. \n3. Search for an Employee. \n4. Update Salary of an Employee \n5. Delete an Employee Records" << endl;
    cout << "\nWhat you want us to do : ";
    cin >> a;

    switch (a)
    {
    case 1:
        newemployee();
        break;
    case 2:
        display();
        break;
    case 3:
        search();
        break;
    case 4:
        update();
        break;
    case 5:
        deletee();
        break;
    }
    
    return 0;
}
