#include <iostream>
using namespace std;
int bst(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;
    int diff1, diff2, diff = 1000, ind;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            // cout << "difference is 0";
            return mid;
        }
        else if (target > arr[mid])
        {
            low = mid + 1;
            diff1 = target - arr[mid];
            diff2 = arr[mid + 1] - target;
            if (diff2 < diff1)
            {
                diff = diff2;
                ind = mid + 1;
            }
            else
            {
                diff = diff1;
                ind = mid;
            }
        }
        else
        {
            high = mid - 1;

            diff1 = target - arr[mid - 1];
            if (diff1 < 0)
            {
                diff1 = diff1 * -1;
            }

            diff2 = arr[mid] - target;
            if (diff2 < diff1)
            {
                diff = diff2;
                ind = mid + 1;
            }
            else
            {
                diff = diff1;
                ind = mid;
            }
        }
    }
    return ind;
}
int main()
{
    int arr[10] = {1, 3, 5, 8, 9, 10, 12, 17, 20, 23};
    int index = bst(arr, 10, 4);
    cout << index;
    return 0;
}