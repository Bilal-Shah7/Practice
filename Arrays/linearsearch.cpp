#include <iostream>
using namespace std;

int main(){
int num;
int arr[3][4]= {{2,4,6,7},{1,2,3,4},{5,6,7,8}};
int found = 0;
cout << "Enter the number you want to search : ";
cin>>num;

for (int i = 0; i<3;i++){

    for (int j=0; j<4; j++){

        if (arr[i][j]==num){
        found++;
            cout << "The number is found at Row : "<<i<< " and at Column : "<<j<<endl;
        }
    }
}
cout << "The number is found at "<<found<< " places."<<endl;

return 0;
}