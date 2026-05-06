#include <iostream>
using namespace std;
void bubblesort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int median(int arr[], int n)
{
    if (n % 2 == 0)
    {
        // int d = ;
        return ((arr[n / 2] - 1) + arr[n / 2]) / 2;
    }
    else
    {
        //  int d = ;
        return arr[n / 2];
    }
}
int main()
{
    int arr[5] = {20, 10, 30, 50, 40};
    int n = sizeof(arr) / sizeof(int);
    bubblesort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    int med = median(arr, 5);
    cout << med << endl;

    return 0;
}