#include <iostream>

using namespace std;

int add(int a, int b) {
    return a + b;
}

int (*p_func)(int , int ) = add;
// int (*p_func_bad)(int , char ) = add;


int main() {
    int a = 1, b = 2;
    cout << "call add: " << a << " + " << b << " = " << add(a, b) << endl;
    cout << "call p_func: " << a << " + " << b << " = " << p_func(a, b) << endl;
    cout << "call (*p_func): " << a << " + " << b << " = " << (*p_func)(a, b) << endl;
    return 0;

}
