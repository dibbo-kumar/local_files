#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[] = {19, 28, 47, 35, 92};
    int n = sizeof(a) / sizeof(a[0]);
    int suma[n];
    for (int i = 0; i < n; i++)
    {
        int num = a[i];
        int sum = 0;
        while (num > 0)
        {
            sum = sum + num % 10;
            num = num / 10;
        }
        suma[i] = sum;
    }

    for (int i = 0; i < n; i++)
    {
        int temp = a[i];
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (suma[j] < suma[min])
            {
                min = j;
            }
        }
        a[i] = a[min];
        a[min] = temp;
    }
    for (int i = 0; i < n; i++)
    {;
        cout << a[i];;
        cout << " ";
    }
};