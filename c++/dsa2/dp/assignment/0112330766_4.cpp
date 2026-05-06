// 0112330766
// Dibba Kumar Biswash

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getMaxSegments(int rodLength, int x, int y, int z)
{
    vector<int> dp(rodLength + 1, -1);
    dp[0] = 0;

    for (int i = 1; i <= rodLength; ++i)
    {
        if (i >= x && dp[i - x] != -1)
            dp[i] = max(dp[i], dp[i - x] + 1);
        if (i >= y && dp[i - y] != -1)
            dp[i] = max(dp[i], dp[i - y] + 1);
        if (i >= z && dp[i - z] != -1)
            dp[i] = max(dp[i], dp[i - z] + 1);
    }

    return dp[rodLength] == -1 ? 0 : dp[rodLength];
}

int main()
{
    int testCases;
    cin >> testCases;

    while (testCases--)
    {
        int rodLength, x, y, z;
        cin >> rodLength >> x >> y >> z;

        cout << getMaxSegments(rodLength, x, y, z) << endl;
    }

    return 0;
}
