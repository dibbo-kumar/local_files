#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int arr[7] = {1, 2, 3, 4, 5, 5, 6};
    int arr2[5] = {1, 2, 4, 4, 5};
    int arr3[5];
    int n = 0, i = 0, j = 0;
    // for (int i = 0; i < 7; i++)
    // {
    //    int element = arr[i];
    //     for (int j = 0; j < 5; j++)
    //     {
    //         if(arr2[j] == element)
    //         {
    //             arr3[n] = arr2[j];
    //             arr2[j] = -100;
    //             n++;
    //             break;
    //         }
    //     }

    // }
    while (i < 7 && j < 5)
    {
        if (arr[i] == arr2[j])
        {
            arr3[n] = arr2[j];
            arr2[j] = -100;
            n++;
        }
        else if (arr[i] < arr2[j])
        {
            i++;
        }
        else if (arr[i] > arr2[j])
        {
            j++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr3[i] << " ";
    }
    cout << endl;

    return 0;
}
