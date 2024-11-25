#include <iostream>
using namespace std;

// changing odd indexed elements to its 2nd multiple
// incrementing even indexed elements by 10

int main(){

    int arr[10] = {2,4,6,8,10,12,14,16,18,20};
    

    for (int i = 0; i<10; i++){
        if (i%2==0){
            arr[i]+=10;
        }
        else {

            arr[i] = arr[i]*2;
        }
        cout << arr[i]<< " ";
    }
    

}