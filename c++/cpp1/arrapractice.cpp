#include <iostream>
using namespace std;
int main()
{
    int a = 6;
    int &b = a;
    cout << a << endl;
    cout << b << endl;
    b = 10;
    cout << a << endl;
    cout << b << endl;

    return 0;
}