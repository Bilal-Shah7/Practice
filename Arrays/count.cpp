#include <iostream>
using namespace std;

int main()
{

    int x = 2;

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int count = 0;

    for (int i = 0; i < 8; i++)
    {
        if (arr[i] > x)
        {
            count++;
        }
    }
    cout << "The Number of Elements greater than 4 are : " << count;

    return 0;
}