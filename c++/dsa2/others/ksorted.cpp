#include <iostream>
#include <vector>
using namespace std;

void sortedPartition(vector<int> &arr, int k)
{
    int n = arr.size();

    // Insertion sort for first k elements
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // Move elements greater than key to one position ahead
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        // Stop if first k elements are sorted
        if (i == k - 1)
            break;
    }

    // Print the first k elements
    for (int i = 0; i < k; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {6, 7, 5, 3, 9, 1};
    int k = 3;

    sortedPartition(arr, k);

    return 0;
}
