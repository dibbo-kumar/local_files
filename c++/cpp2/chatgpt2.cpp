#include <iostream>
using namespace std;

void frequencySort(int arr[], int n) {
    int freq[1000] = {0};  // Frequency array (assuming values are < 1000)

    // Step 1: Count occurrences of each element
    for (int i = 0; i < n; i++)
        freq[arr[i]]++;

    // Step 2: Sort array manually (Nested Loop)
    for (int i = 0; i < n ; i++) {
        for (int j = i ; j < n; j++) {
            if (freq[arr[j]] > freq[arr[i]] || 
               (freq[arr[j]] == freq[arr[i]] && arr[j] < arr[i])) {
                swap(arr[i], arr[j]);  // Swap elements
            }
        }
    }

    // Step 3: Print sorted array
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    
    cout << endl;
}

int main() {
    int arr[] = {4, 3, 1, 6, 1, 3,3,3, 4, 4,4,4};
    int n = sizeof(arr) / sizeof(arr[0]);

    frequencySort(arr, n);

    return 0;
}
