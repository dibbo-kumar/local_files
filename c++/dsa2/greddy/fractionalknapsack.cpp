#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    cout << "enter n and total";
    int n, total;
    cin >> n >> total;
    vector<int> value(n), weight(n);
    for (int i = 0; i < n; i++)
    {
        cin >> value[i] >> weight[i];
    }
    vector<pair<double, int>> ratio(n);
    for (int i = 0; i < n; i++)
    {
        ratio[i] = {(double)value[i] / weight[i], i};
    }

    sort(ratio.rbegin(), ratio.rend());
    double max = 0.0;
    int remain = total;
    for (int i = 0; i < n; i++)
    {
        if (remain == 0)
        {
            break;
        }
        int idx = ratio[i].second;
        if (weight[idx] <= remain)
        {
            max += value[idx];
            remain -= weight[idx];
            cout << "item no. " << idx + 1 << "value is " << value[idx] << "weight is " << weight[idx] << endl;
        }
        else
        {
            double val = remain * ratio[i].first;
            max += val;
            cout << "item no. " << idx + 1 << "value is " << val << "weight is " << remain << endl;
            remain = 0;
        }
    }
    cout << "max is " << max;
}