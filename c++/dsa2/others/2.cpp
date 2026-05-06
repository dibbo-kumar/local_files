#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void msdSort(vector<int> &a, int l, int r, int exp, int base) {
    if (l >= r || exp == 0) return;

    vector<queue<int>> buckets(base);

    for (int i = l; i <= r; i++) {
        int digit = (a[i] / exp) % base;
        buckets[digit].push(a[i]);
    }

    int idx = l;
    for (int b = 0; b < base; b++) {
        int start = idx;
        while (!buckets[b].empty()) {
            a[idx++] = buckets[b].front();
            buckets[b].pop();
        }
        int end = idx - 1;
        if (start < end) msdSort(a, start, end, exp / base, base);
    }
}

int main() {
    int n, base;
    cin >> n >> base;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
    cin >> a[i];

    int maxVal = *max_element(a.begin(), a.end());

    int exp = 1;
    while (maxVal / exp >= base) exp *= base;

    msdSort(a, 0, n - 1, exp, base);

    for (int x : a) cout << x << ' ';
    cout << endl;
    return 0;
}
/*
i can't identify the time complexity of this function
*/