#include <iostream>
using namespace std;

int main()
{

    int n;
    cout << "Enter limit of natural number of which you want the square : ";
    cin >> n;

    int arr[n];
    int c = 0;
    cout << "The first (" << n << ") Natural numbers are : ";

    for (int i = 0; i < n; i++)
    {
        c++;
        arr[i] = c;
        cout << arr[i] << " ";
    }

    cout << "\nThe squares of the first (" << n << ") Natural numbers are : ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] * arr[i] << " ";
    }
}