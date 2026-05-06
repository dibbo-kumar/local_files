#include <bits/stdc++.h>
using namespace std;

void minCoinsUsed(vector<int> &coins, int amount)
{
    int inf = INT_MAX;
    vector<int> dp(amount + 1, inf);
    vector<int> coinUsed(amount + 1, -1);
    vector<long long> ways(amount + 1, 0);
    dp[0] = 0;
    ways[0] = 1;
    for (int i = 1; i <= amount; i++)
    {
        for (int coin : coins)
        {
            if (i >= coin && dp[i - coin] != inf && dp[i - coin] + 1 < dp[i])
            {
                dp[i] = dp[i - coin] + 1;
                coinUsed[i] = coin;
            }
        }
    }
    
    for (int coin : coins)
    {
        for (int i = coin; i <= amount; i++)
        {
            ways[i] += ways[i - coin];
        }
    }

    if (dp[amount] == inf)
    {
        cout << "amount can not be made";
        return;
    }
    cout << "minimum coin used is " << dp[amount] << endl;
    cout << "coin used : ";
    int am = amount;
    while (am > 0)
    {
        cout << coinUsed[am] << "  ";
        am -= coinUsed[am];
    }
    cout << endl;
    cout << "number of ways are " << ways[amount];
}

int main()
{
    int n, amount;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    cin >> amount;
    minCoinsUsed(coins, amount);
    return 0;
}
