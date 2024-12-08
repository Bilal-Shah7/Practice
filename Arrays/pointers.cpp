#include <iostream>
using namespace std;
int main(){

int a = 2;
int*ptr = &a;

int marks[]= {2,4};
cout << marks<<endl;
int *p = marks;
*(p++);
cout <<*p<<endl;
p++;
cout <<*p<<endl;
cout <<*p<<endl;
cout <<*p<<endl;
cout <<*p<<endl;
p++;
cout <<p;
}