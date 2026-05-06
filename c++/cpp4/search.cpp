#include <iostream>
using namespace std;

int bst(int arr[], int n, int target)
{
    int low = 0, high = n - 1;
    int ind = 0;
    int minDiff = 1e9; // large number

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int diff = arr[mid] - target;
        if (diff < 0) diff = -diff;

        // Update index if this element is closer
        if (diff < minDiff || (diff == minDiff && arr[mid] < arr[ind])) {
            minDiff = diff;
            ind = mid;
        }

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return ind;
}

int main()
{
    int arr[10] = {1, 3, 5, 8, 9, 10, 12, 17, 20, 23};
    int index = bst(arr, 10, 4);
    cout << "Closest index: " << index << ", value: " << arr[index] << endl;
    return 0;
}
