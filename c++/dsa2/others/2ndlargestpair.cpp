#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Function to find largest and second largest using divide & conquer
void findLargestSecondLargest(vector<int> &arr, int left, int right, int &largest, int &secondLargest)
{
    // Base case: only one element
    if (left == right)
    {
        largest = arr[left];
        secondLargest = INT_MIN; // no second largest
        return;
    }

    int mid = left + (right - left) / 2;

    // Recurse on left and right halves
    int l1, s1, l2, s2;
    findLargestSecondLargest(arr, left, mid, l1, s1);
    findLargestSecondLargest(arr, mid + 1, right, l2, s2);

    // Combine: find largest and second largest from l1, s1, l2, s2
    if (l1 > l2)
    {
        largest = l1;
        secondLargest = max(l2, s1);
    }
    else
    {
        largest = l2;
        secondLargest = max(l1, s2);
    }
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

    int largest, secondLargest;
    findLargestSecondLargest(arr, 0, n - 1, largest, secondLargest);

    cout << "Largest element: " << largest << endl;
    cout << "Second largest element: " << secondLargest << endl;

    return 0;
}
