// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// int main()
// {
//     int n = 3;
//     vector<pair<int, int>> a(n);
//     int s, f;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> s >> f;
//         a[i] = {f, s};
//     }
//     sort(a.begin(), a.end());
//     int lastFinish = -1;
//     int count = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int f = a[i].first;
//         int s = a[i].second;
//         if (s >= lastFinish)
//         {
//             cout << "start is" << s << "end is " << f << endl;
//             lastFinish = f;
//             count++;
//         }
//     }
//     cout << count << endl;

//     return 0;
// }
