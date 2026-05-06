#include <iostream>
#include <vector>
using namespace std;

// Function to find maximum using divide & conquer
int findMax(vector<int> &arr, int left, int right)
{
    // Base case: only one element
    if (left == right)
    {
        return arr[left];
    }

    int mid = left + (right - left) / 2;

    int maxLeft = findMax(arr, left, mid);
    int maxRight = findMax(arr, mid + 1, right);

    return (maxLeft > maxRight) ? maxLeft : maxRight;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int maximum = findMax(arr, 0, n - 1);

    cout << "Maximum number = " << maximum << endl;

    return 0;
}
