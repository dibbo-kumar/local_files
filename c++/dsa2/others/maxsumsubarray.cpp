#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find max crossing sum
int maxCrossingSum(vector<int> &arr, int left, int mid, int right)
{
    int sum = 0;
    int leftSum = INT_MIN;

    for (int i = mid; i >= left; i--)
    {
        sum += arr[i];
        leftSum = max(leftSum, sum);
    }

    sum = 0;
    int rightSum = INT_MIN;
    for (int i = mid + 1; i <= right; i++)
    {
        sum += arr[i];
        rightSum = max(rightSum, sum);
    }

    return leftSum + rightSum;
}

// Function to find max subarray sum using divide and conquer
int maxSubArraySum(vector<int> &arr, int left, int right)
{
    if (left == right)
    {
        return arr[left]; // Base case: only one element
    }

    int mid = (left + right) / 2;

    int leftMax = maxSubArraySum(arr, left, mid);
    int rightMax = maxSubArraySum(arr, mid + 1, right);
    int crossMax = maxCrossingSum(arr, left, mid, right);

    return max({leftMax, rightMax, crossMax});
}

int main()
{
    vector<int> arr = {2, -4, 3, 5, -1, 2, -4, 6};
    int n = arr.size();

    int maxSum = maxSubArraySum(arr, 0, n - 1);
    cout << "Maximum Subarray Sum: " << maxSum << endl;

    return 0;
}
