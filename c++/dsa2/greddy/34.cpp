#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n = 4;
    vector<double> value = {840, 870, 2000, 500};
    vector<int> weightr = {12, 10, 8, 5};

    vector<pair<double, int>> ratio(n);
    for (int i = 0; i < n; i++)
    {
        ratio[i] = {(double)value[i] / weightr[i], i};
    }

    sort(ratio.rbegin(), ratio.rend());
    vector<int> weight = weightr;
    for (int i = 0; i < 4; i++)
    {
        double max = 0.0;
        int remain = 9;
        cout << "for thief " << i + 1;
        for (int j = 0; j < n; j++)
        {
            if (remain == 0)
            {
                break;
            }
            int idx = ratio[j].second;
            if (weight[idx] == 0)
            {
                continue;
            }

            if (weight[idx] <= remain)
            {
                max += value[idx];
                remain -= weight[idx];
                weight[idx] = 0;
                // cout << "item no. " << idx + 1 << " value is " << value[idx]  << endl;
            }
            else
            {
                double val = remain * ratio[j].first;
                max += val;
                weight[idx] -= remain;
                value[idx] -= val;
                // cout << "item no. " << idx + 1 << " value is " << val << " weight is " << remain << endl;
                remain = 0;
            }
        }
        cout << "max is " << max << endl;
    }
}