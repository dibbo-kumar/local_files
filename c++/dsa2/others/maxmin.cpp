#include <iostream>
#include <vector>
using namespace std;

// Function to find min and max using divide & conquer
void findMinMax(vector<int> &arr, int left, int right, int &minVal, int &maxVal)
{
    // Base case: only one element
    if (left == right)
    {
        minVal = maxVal = arr[left];
        return;
    }

    // Base case: two elements
    if (right == left + 1)
    {
        if (arr[left] < arr[right])
        {
            minVal = arr[left];
            maxVal = arr[right];
        }
        else
        {
            minVal = arr[right];
            maxVal = arr[left];
        }
        return;
    }

    // Divide
    int mid = left + (right - left) / 2;

    // Conquer
    int leftMin, leftMax, rightMin, rightMax;
    findMinMax(arr, left, mid, leftMin, leftMax);
    findMinMax(arr, mid + 1, right, rightMin, rightMax);

    // Combine
    minVal = (leftMin < rightMin) ? leftMin : rightMin;
    maxVal = (leftMax > rightMax) ? leftMax : rightMax;
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

    int minVal, maxVal;
    findMinMax(arr, 0, n - 1, minVal, maxVal);

    cout << "Minimum number = " << minVal << endl;
    cout << "Maximum number = " << maxVal << endl;

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

// Function to find max and min using divide & conquer
pair<int, int> Find_maxmin(vector<int> &A, int i, int j)
{
    // Base case: one element
    if (i == j)
    {
        return {A[i], A[i]}; // max = min = A[i]
    }

    // Divide
    int mid = (i + j) / 2;

    // Conquer
    pair<int, int> left = Find_maxmin(A, i, mid);
    pair<int, int> right = Find_maxmin(A, mid + 1, j);

    int mx1 = left.first, min1 = left.second;
    int mx2 = right.first, min2 = right.second;

    // Combine
    int fmax, fmin;
    if (mx1 > mx2)
        fmax = mx1;
    else
        fmax = mx2;

    if (min1 < min2)
        fmin = min1;
    else
        fmin = min2;

    return {fmax, fmin};
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> A(n);
    cout << "Enter elements: ";
    for (int k = 0; k < n; k++)
        cin >> A[k];

    pair<int, int> result = Find_maxmin(A, 0, n - 1);

    cout << "Maximum = " << result.first << endl;
    cout << "Minimum = " << result.second << endl;

    return 0;
}
