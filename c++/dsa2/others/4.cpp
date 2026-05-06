#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void RadixSort(vector<int> &a, int base)
{
    int maxVal = 0;
    for (int x : a)
        maxVal = max(maxVal, x);

    for (int exp = 1; maxVal / exp > 0; exp *= base)
    {
        vector<queue<int>> buckets(base);

        for (int x : a)
        {
            int digit = (x / exp) % base;
            buckets[digit].push(x);
        }

        int idx = 0;
        for (int b = 0; b < base; b++)
        {
            while (!buckets[b].empty())
            {
                a[idx++] = buckets[b].front();
                buckets[b].pop();
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> b = a;
    RadixSort(b, 2);
    cout << "Base 2 :";
    for (int x : b)
        cout << x << " ";
    cout << endl;

    b = a;
    RadixSort(b, 10);
    cout << "Base 10: ";
    for (int x : b)
        cout << x << " ";
    cout << endl;

    b = a;
    RadixSort(b, 256);
    cout << "Base 256:";
    for (int x : b)
        cout << x << " ";
    cout << endl;

    return 0;
}
