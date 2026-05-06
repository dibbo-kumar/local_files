// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// int binarysearch(vector<int> &a, int low, int high, int target, int step)
// {
//     if (low > high)
//     {
//         return step;
//     }
//     step++;
//     int mid = (low + high) / 2;
//     if (a[mid] == target)
//     {
//         return step;
//     }
//     else if (a[mid] > target)
//     {
//         return binarysearch(a, low, mid - 1, target, step);
//     }
//     else
//     {
//         return binarysearch(a, mid + 1, high, target, step);
//     }
// }
// int main()
// {
//     int key, n;
//     cout << "enter size: " << endl;
//     cin >> n;
//     vector<int> a(n);
//     cout<<"enter element";
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     cout << "enter key: " << endl;
//     cin >> key;
//     int step = 0;
//     cout << binarysearch(a, 0, n - 1, key, step);
//     return 0;
// }

/*,,,,,,,,,,,,merger sort ,,,,,,,,,*/

// #include <iostream>
// #include <vector>
// using namespace std;

// void mergesort(vector<int> &a, int m, int l, int h)
// {
//     int n1 = m - l + 1;
//     int n2 = h - m;
//     vector<int> L(n1);
//     vector<int> R(n2);
//     for (int i = 0; i < n1; i++)
//     {
//         L[i] = a[l + i];
//     }
//     for (int j = 0; j < n2; j++)
//     {
//         R[j] = a[m + j + 1];
//     }
//     int i = 0, j = 0, k = l;
//     while (i < n1 && j < n2)
//     {
//         if (L[i] < R[j])
//         {
//             a[k++] = L[i++];
//         }
//         else
//             a[k++] = R[j++];
//     }
//     while (i < n1)
//     {
//         a[k++] = L[i++];
//     }
//     while (j < n2)
//     {
//         a[k++] = R[j++];
//     }
// }
// void merge(vector<int> &a, int l, int h)
// {
//     if (l == h)
//     {
//         return;
//     }
//     int mid = (l + h) / 2;
//     merge(a, l, mid);
//     merge(a, mid + 1, h);
//     mergesort(a, mid, l, h);
// }
// int main()
// {

//     int key, n;
//     cout << "enter size: " << endl;
//     cin >> n;
//     vector<int> a(n);
//     cout << "enter element ; ";
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     merge(a, 0, n - 1);
//     for (int x : a)
//         cout << x << " ";
//     return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;

// int maxSubarraySum(vector<int> &a) {
//     int maxSoFar = a[0];
//     int currSum = a[0];

//     for (int i = 1; i < a.size(); i++) {
//         currSum = max(a[i], currSum + a[i]);  // extend or start new subarray
//         maxSoFar = max(maxSoFar, currSum);    // update maximum
//     }

//     return maxSoFar;
// }

// int main() {
//     int n;
//     cout << "Enter size: ";
//     cin >> n;

//     vector<int> a(n);
//     cout << "Enter elements: ";
//     for (int i = 0; i < n; i++) cin >> a[i];

//     cout << "Maximum Subarray Sum: " << maxSubarraySum(a) << endl;
//     return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;
// int max(vector<int> &a, int l, int r)
// {
//     if (l == r)
//     {
//         if (a[l] % 2 == 0)
//         {
//             return a[l];
//         }
//         else
//         return 0;
//     }
//     int m = (l + r) / 2;
//     int l1 = max(a, l, m);
//     int r1 = max(a, m + 1, r);
//     return l1 + r1;
// }
// int main()
// {
//     int n;
//     cout << "Enter size: ";
//     cin >> n;

//     vector<int> a(n);
//     cout << "Enter elements: ";
//     for (int i = 0; i < n; i++)
//         cin >> a[i];
//     cout << max(a, 0, n - 1);
// }

// #include <iostream>
// #include <vector>
// using namespace std;
// int max(vector<int> &a, int l, int r)
// {
//     if (l == r)
//     {
//         if (a[l] % 2 == 0)
//         {
//             return a[l];
//         }
//         else
//         return 0;
//     }
//     int m = (l + r) / 2;
//     int l1 = max(a, l, m);
//     int r1 = max(a, m + 1, r);
//     return l1 + r1;
// }
// int main()
// {
//     int n;
//     cout << "Enter size: ";
//     cin >> n;

//     vector<int> a(n);
//     cout << "Enter elements: ";
//     for (int i = 0; i < n; i++)
//         cin >> a[i];
//     cout << max(a, 0, n - 1);
// }
// #include <iostream>
// #include <vector>
// #include <climits>
// using namespace std;
// void findLargestPair(int arr[], int l, int h, int &max1, int &max2)
// {
//     if (l == h)
//     {
//         max1 = arr[l];
//         max2 = INT_MIN;
//         return;
//     }
//     else if (h == l + 1)
//     {
//         if (arr[l] < arr[h])
//         {
//             max1 = arr[h];
//             max2 = arr[l];
//         }
//         else
//         {
//             max1 = arr[l];
//             max2 = arr[h];
//         }
//         return;
//     }
//     int mid = (l + h) / 2;
//     int l1, l2, r1, r2;
//     findLargestPair(arr, l, mid, l1, l2);
//     findLargestPair(arr, mid + 1, h, r1, r2);

//     if (l1 > r1)
//     {
//         max1 = l1;
//         max2 = max(r1, l2);
//     }
//     else if (l1 < r1)
//     {
//         max1 = r1;
//         max2 = max(l1, r2);
//     }
//     return;
// }

// int main()
// {
//     int arr[] = {12, 45, 67, 23, 89, 34, 90, 11};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     int max1, max2;
//     findLargestPair(arr, 0, n - 1, max1, max2);

//     cout << "Largest: " << max1 << endl;
//     cout << "Second Largest: " << max2 << endl;

//     return 0;
// }
// #include <iostream>
// #include <vector>
// #include <climits>
// using namespace std;

// int crosssum(int arr[], int l, int m, int r)
// {
//     int sum = 0;
//     int lefts = INT_MIN;
//     for (int i = m; i >= l; i--)
//     {
//         sum = sum + arr[i];
//         if (lefts < sum)
//         {
//             lefts = sum;
//         }
//     }
//     sum = 0;
//     int rights = INT_MIN;
//     for (int i = m+1; i <= r; i++)
//     {
//         sum = sum + arr[i];
//         if (rights < sum)
//         {
//             rights = sum;
//         }
//     }
//     return lefts + rights;
// }

// int maxs(int arr[], int l, int r)
// {
//     if (l == r)
//     {
//         return arr[l];
//     }
//     int mid = (l + r) / 2;
//     int leftsum = maxs(arr, l, mid);
//     int rightsum = maxs(arr, mid + 1, r);
//     int cross = crosssum(arr, l, mid, r);
//     return max ( leftsum, max(rightsum, cross));
// }
// int main()
// {
//     int arr[] = {2, -4, 3, -1, 2, -4, 3, 2};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     int max_sum = maxs(arr, 0, n - 1);

//     cout << "Maximum Subarray Sum = " << max_sum << endl;
//     return 0;
// }
//
//
//
// #include <iostream>
// #include <vector>
// #include <climits>
// using namespace std;

// int crosssum(int arr[], int l, int m, int r)
// {
//     int sum = 0;
//     int lefts = INT_MIN;
//     for (int i = m; i >= l; i--)
//     {
//         if (arr[i]<0)
//         {
//             break;
//         }
        
//         sum = sum + arr[i];
//         if (lefts < sum)
//         {
//             lefts = sum;
//         }
//     }
//     sum = 0;
//     int rights = INT_MIN;
//     for (int i = m+1; i <= r; i++)
//     {
//         if (arr[i]<0)
//         {
//             break;
//         }
//         sum = sum + arr[i];
//         if (rights < sum)
//         {
//             rights = sum;
//         }
//     }
//     return lefts + rights;
// }

// int maxs(int arr[], int l, int r)
// {
//     if (l == r)
//     {
//         if (arr[l]<0)
//         {
//             return 0;
//         }
        
//         return arr[l];
//     }
//     int mid = (l + r) / 2;
//     int leftsum = maxs(arr, l, mid);
//     int rightsum = maxs(arr, mid + 1, r);
//     int cross = crosssum(arr, l, mid, r);
//     return max ( leftsum, max(rightsum, cross));
// } 


// int main()
// {
//     int arr[] = {2, -4, 3, 1, 2, -4, 3, 2};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     int max_sum = maxs(arr, 0, n - 1);

//     cout << "Maximum Subarray Sum = " << max_sum << endl;
//     return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;

// struct Student {
//     string name;
//     int id;
//     double cgpa;
// };

// // Recursive function to find student with highest CGPA
// Student highestCGPA(vector<Student> &students, int l, int r) {
//     if (l == r) {
//         return students[l];  // only one student
//     }

//     int mid = (l + r) / 2;

//     Student leftMax  = highestCGPA(students, l, mid);
//     Student rightMax = highestCGPA(students, mid + 1, r);

//     // Compare CGPAs and return the higher one
//     if (leftMax.cgpa > rightMax.cgpa)
//         return leftMax;
//     else
//         return rightMax;
// }

// int main() {
//     int n;
//     cout << "Enter number of students: ";
//     cin >> n;

//     vector<Student> students(n);

//     for (int i = 0; i < n; i++) {
//         cout << "Enter name, id, cgpa: ";
//         cin >> students[i].name >> students[i].id >> students[i].cgpa;
//     }

//     Student top = highestCGPA(students, 0, n - 1);

//     cout << "\nStudent with highest CGPA:\n";
//     cout << "Name: " << top.name << endl;
//     cout << "ID: "   << top.id << endl;
//     cout << "CGPA: " << top.cgpa << endl;

//     return 0;
// }

