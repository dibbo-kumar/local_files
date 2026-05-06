#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n = 5, amount = 31;
    vector<int> coin(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }
    sort(coin.rbegin(), coin.rend());
    vector<int> used(n, 0);
    for (int i = 0; i < n; i++)
    {
        used[i] = amount / coin[i];
        amount = amount % coin[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << coin[i] << "used :" << used[i]<< endl;
    }
    if (amount != 0)
    {
        cout << "cant make that amount by that coins" <<endl;

    }
    
}