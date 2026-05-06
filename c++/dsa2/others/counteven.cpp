#include <iostream>
#include <vector>
using namespace std;

int countEven(vector<int> &arr, int left, int right)
{
    // Base case: one element
    if (left == right)
    {
        return (arr[left] % 2 == 0) ? 1 : 0;
    }

    // Divide
    int mid = (left + right) / 2;

    // Conquer
    int leftCount = countEven(arr, left, mid);
    int rightCount = countEven(arr, mid + 1, right);

    // Combine
    return leftCount + rightCount;
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

    int result = countEven(arr, 0, n - 1);

    cout << "Count of even numbers = " << result << endl;

    return 0;
}
