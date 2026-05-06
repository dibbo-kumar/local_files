#include <iostream>
#include <vector>
#include <utility>
using namespace std;
pair<int, int> maxs(int arr[], int l, int r, int size)
{
    if (l == r)
    {
        if ((size - l) >= 2)
        {
            return {(arr[l] + arr[l + 1] + arr[l + 2]), l};
        }
        else
            return {0, 0};
    }
    int mid = (l + r) / 2;
    pair<int, int> leftsum = maxs(arr, l, mid, size);
    pair<int, int> rightsum = maxs(arr, mid + 1, r, size);
    if (leftsum.first > rightsum.first)
    {
        return {leftsum.first, leftsum.second};
    }
    else
        return {rightsum.first, rightsum.second};
}
int main()
{
    int arr[] = {2, 4, 3, -1, 7, -4, 3, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    pair<int, int> max_sum = maxs(arr, 0, n - 1, n - 1);

    cout << "Maximum = " << max_sum.first << " indexs are  " << max_sum.second << " " << max_sum.second + 1 << " " << max_sum.second + 2 << endl;
    return 0;
}