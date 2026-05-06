#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int arr[7] = {1, 3, 3, 4, 5, 4, 6};

    int ans = 0;
    int ind = 0;
    for (int i = 0; i < 7; i++)
    {
        ans = ans ^ arr[i];
    }
    for (int i = 0; i < 7; i++)
    {
        ans = ans ^ i;
    }
    cout << "unique element : " << ans << endl;

    return 0;
}
