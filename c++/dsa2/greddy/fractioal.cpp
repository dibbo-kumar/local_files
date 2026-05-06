// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main() {
//     int n;
//     cout << "Enter number of items: ";
//     cin >> n;

//     vector<int> value(n), weightr(n);

//     cout << "Enter values (profits): ";
//     for (int i = 0; i < n; i++) {
//         cin >> value[i];
//     }

//     cout << "Enter weights: ";
//     for (int i = 0; i < n; i++) {
//         cin >> weightr[i];
//     }

//     int capacity;
//     cout << "Enter knapsack capacity: ";
//     cin >> capacity;

//     // Calculate value/weight ratio
//     vector<pair<double, int>> ratio(n);
//     for (int i = 0; i < n; i++) {
//         ratio[i] = {(double)value[i] / weightr[i], i};
//     }

//     // Sort by descending ratio
//     sort(ratio.rbegin(), ratio.rend());

//     double maxProfit = 0.0;
//     int remain = capacity;
//     vector<int> weight = weightr;

//     for (int i = 0; i < n; i++) {
//         if (remain == 0) break;

//         int idx = ratio[i].second;
//         if (weight[idx] == 0) continue;

//         if (weight[idx] <= remain) {
//             maxProfit += value[idx];
//             remain -= weight[idx];
//             weight[idx] = 0;
//         } else {
//             double val = remain * ratio[i].first;
//             maxProfit += val;
//             weight[idx] -= remain;
//             remain = 0;
//         }
//     }

//     cout << "Maximum profit = " << maxProfit << endl;

//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n = 4;
    int capacity = 9;
    // Values (profit in taka for whole item)
    vector<int> value = {840, 870, 2000, 500};

    // Weights (kg of each item)
    vector<int> weight = {12, 10, 8, 5};
    vector<pair<double, int>> ratio(n);
    for (int i = 0; i < n; i++)
    {
        ratio[i] = {(double)value[i] / weight[i], i};
    }
    sort(ratio.rbegin(), ratio.rend());
    double profit = 0.0;
    int remain = capacity;
    for (int i = 0; i < n; i++)
    {
        if (remain == 0)
        {
            break;
        }
        else
        {
            int idx = ratio[i].second;
            if (weight[idx] <= capacity)
            {
                profit += value[idx];
                capacity -= weight[idx];
            }
            else
            {
                double val = capacity * ratio[i].first;
                profit += val;
                capacity = 0;
            }
        }
    }
}
