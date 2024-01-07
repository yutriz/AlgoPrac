#include <iostream>

void swap(int& a, int& b){
    a ^= b;
    b ^= a;
    a ^= b;
}

void pswap(int *&a, int *&b){  // right to left: a -- refer -- pointer 
    // do something 

}

using namespace std;

int main() {
    int a = 12;
    int b = 23;
    cout << "a is " << a << endl;
    cout << "b is " << b << endl;
    cout << "after swaping\n";
    swap(a, b);
    cout << "a is " << a << endl;
    cout << "b is " << b << endl;

}

