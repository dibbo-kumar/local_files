#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int maxVal = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        maxVal = max(maxVal, a[i]);
    }

    vector<int> count(maxVal + 1, 0);
    for (int x : a)
        count[x]++;

    for (int i = maxVal - 1; i >= 0; --i)
    {
        count[i] += count[i + 1];
    }

    vector<int> output(n);
    for (int i = 0; i < n; ++i)
    {
        output[--count[a[i]]] = a[i];
    }

    for (int x : output)
        cout << x << ' ';
    cout << endl;

    return 0;
}
/*
time complexity of both ascending and descending cases is same .
and that is O(n+k) , because both cases loop runs the same times .

and space complexity is also same , because in both cases , need extra array 
tgat has size of maximum element of the array . and that is O(n+k) , for both cases/

*/