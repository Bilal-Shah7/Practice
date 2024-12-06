#include <iostream>
using namespace std;
int main()
{
    int seat;
    int bus[10] = {0};
    char otherseat;
    bool flag = true;
    while (true)
    {

        cout << "Enter Seat No. of your desired seat : ";
        cin >> seat;

        if (seat > 10 || seat < 0)
        {
            cout << "Invalid number" << endl;
            continue;
        };

        if (bus[seat - 1] == 1)
        {
            cout << "Sorry ! seat is already reserved." << endl;
        }
        else if (bus[seat - 1] == 0)
        {
            bus[seat - 1] = 1;
            cout << "Seat has been booked successfully" << endl;
            ;
        }

        cout << "Do you want to book another seat ? (y/n) : ";
        cin >> otherseat;
        if (otherseat == 'n' || otherseat == 'N')
        {
            flag = false;
            break;
        }
    }
    return 0;
}