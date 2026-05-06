#include <iostream>
#include <vector>
#include <string>
using namespace std;


void Counting(vector<string> &strings, int index, int alphabetSize) {
    int n = strings.size();
    vector<int> counts(alphabetSize, 0);
    vector<string> sorted(n);

    for (const auto &s : strings) {
        unsigned char c = s[index];
        counts[c]++;
    }

    for (int i = 1; i < alphabetSize; ++i)
        counts[i] += counts[i - 1];


    for (int i = n - 1; i >= 0; --i) {
        unsigned char c = strings[i][index];
        sorted[--counts[c]] = strings[i];
    }

    strings = sorted;
}


void radix(vector<string> &strings, int alphabetSize) {
    if (strings.empty()) return;

    int strLen = strings[0].size();


    for (int i = strLen - 1; i >= 0; --i)
        Counting(strings, i, alphabetSize);
}

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    radix(arr, 256);

    for (const auto &s : arr)
        cout << s << "\n";

    return 0;
}
