#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter knapsack capacity: ";
    cin >> W;

    vector<int> weight(n + 1), value(n + 1);

    cout << "Enter weight and value for each item:\n";
    for (int i = 1; i <= n; i++)
        cin >> weight[i] >> value[i];

    // DP table
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Fill DP table
    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (weight[i] <= w)
                dp[i][w] = max(dp[i - 1][w],
                               value[i] + dp[i - 1][w - weight[i]]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // Backtrack to find which items are chosen
    vector<int> chosenItems;
    int w = W;
    for (int i = n; i >= 1; i--)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            chosenItems.push_back(i);
            w -= weight[i];
        }
        if (w == 0)
            break;
    }
    reverse(chosenItems.begin(), chosenItems.end());

    // Output results
    cout << "\n✅ Maximum Value: " << dp[n][W] << "\n";

    cout << "📦 Chosen Items: ";
    if (chosenItems.empty())
        cout << "None";
    else
        for (int i : chosenItems)
            cout << "Item " << i << " (w=" << weight[i]
                 << ", v=" << value[i] << ")  ";
    cout << "\n\n📊 DP Table:\n";

    // Print DP table neatly
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
            cout << setw(4) << dp[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
