#include <iostream>
using namespace std;

const int ROWS = 5;
const int COLS = 6;

void availableseat(int cinema[ROWS][COLS], int row, int col)
{
    row--;
    col--;

    if (cinema[row][col] == 0)
    {

        cout << "Your desired seat is availaible" << endl;
    }
    else
    {
        cout << "Sorry! Seat is already reserved." << endl;
    }
}

int seatcount(int cinema[ROWS][COLS])
{
    int count = 0;

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {

            if (cinema[i][j] == 0)
            {
                count++;
            }
        }
    }

    return count;
}

void firstavseat(int cinema[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {

            if (cinema[i][j] == 0)
            {
                cout << "The first available seat is at ROW No." << i + 1 << " and COLUMN No." << j + 1 << endl;
                return;
            }
        }
        cout << "No seat is available";
    }
}

int main()
{

    int cinema[ROWS][COLS] = {
        {1, 1, 1, 0, 0, 1},
        {1, 0, 1, 0, 0, 1},
        {0, 1, 1, 0, 1, 1},
        {1, 0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1, 1},
    };
    int choice;
    int row;
    int col;
    do
    {
        cout << "Cinema Settings" << endl;
        cout << "1. For checking available seat.\n2. For number of available seats.\n3. For checking the first available seat.\n4. Exit Menu. " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Kindly Enter Row Number of your desired seat : ";
            cin >> row;
            cout << "Kindly Enter Column Number of your desired seat : ";
            cin >> col;
            availableseat(cinema, row, col);
            break;

        case 2:
            cout << "The number of available seats are : " << seatcount(cinema) << endl;
            break;

        case 3:
            firstavseat(cinema);
            break;

        case 4:
            cout << "Exiting system...";
            break;

        default:
            cout << "Invalid Input ! Try again.";
        }
    } while (choice != 4);
}