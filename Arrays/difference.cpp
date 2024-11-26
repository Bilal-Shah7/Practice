#include <iostream>
using namespace std;

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int even = 0;
    int odd = 0;
    int diff;
    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
        {
            even = even + arr[i];
        }
        else
        {
            odd = odd + arr[i];
        }
    }

    cout << "Sum of elements on even indices : " << even << endl;
    cout << "Sum of elements on odd indices  : " << odd << endl;
    if (even > odd)
    {
        diff = even - odd;
    }
    else
    {
        diff = odd - even;
    }

    cout << "Difference b/w sum of even and odd : " << diff;
    return 0;
}