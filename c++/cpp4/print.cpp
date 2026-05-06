#include <iostream>
using namespace std;
int main()
{
    int k = 0;
    for (int i = 1; i < 1000; i = i * 2)
    {
        for (int j = 1; j < i; j++)
        {
            cout << ++k << " ";
        }
    }
    cout << "done";
    return 0;
}