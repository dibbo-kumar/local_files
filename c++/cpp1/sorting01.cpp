#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int arr[7] = {1, 0, 1, 0, 0, 1, 0};

    int ans = 0;
    int ind = 0, i = 0, j = 6;
    while (i <= j)
    {
        if (arr[i] == 0)
            i++;
        else if (arr[j] == 1)
            j--;
        else if (arr[i] == 1 && arr[j] == 0)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        cout << "for " << i << ":";
        for (int i = 0; i < 7; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    cout << "for l:";
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
   
    return 0;
}