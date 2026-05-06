#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n = 4;

    // Values (profit in taka for whole item)
    vector<int> value = {840, 870, 2000, 500};

    // Weights (kg of each item)
    vector<int> weight = {12, 10, 8, 5};

    // value/weight ratio with index
    vector<pair<double, int>> ratio(n);
    for (int i = 0; i < n; i++)
    {
        ratio[i] = {(double)value[i] / weight[i], i};
    }

    // sort by ratio descending
    sort(ratio.rbegin(), ratio.rend());

    int thiefNo = 0;

    while (true) {
        thiefNo++;
        int remain = 9;          // bag capacity
        double maxProfit = 0.0;  // profit for this thief

        cout << "For thief " << thiefNo << ":\n";

        bool anyLeft = false; // check if anything is left for this thief

        for (int i = 0; i < n; i++) {
            int idx = ratio[i].second;
            if (weight[idx] == 0) continue; // item finished

            anyLeft = true;

            if (weight[idx] <= remain) {
                maxProfit += value[idx];
                remain -= weight[idx];
                weight[idx] = 0;
            } else {
                double val = remain * ratio[i].first;
                maxProfit += val;
                weight[idx] -= remain;
                remain = 0;
            }

            if (remain == 0) break; // thief's bag is full
        }

        if (!anyLeft) break; // shop empty, stop

        cout << "Max value = " << maxProfit << "\n\n";
    }

    cout << "Total thieves needed = " << thiefNo << endl;

    return 0;
}
