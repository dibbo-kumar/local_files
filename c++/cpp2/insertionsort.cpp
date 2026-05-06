#include <iostream>
#include <climits>
using namespace std;
int main()
{
   int arr[10] = {5, 554, 8, 77, 799, 39, 22, 98, 54, 87};
   // int arr[] = {4, -5, 6, 88, 6, -9, 4, -7};
   int n = sizeof(arr) / sizeof(int);
   // cout << n << endl;
   for (int i = 0; i < n; i++)
      cout << arr[i] << " ";
   cout << endl;
   for (int i = 1; i < n; i++)
   {
      int key = arr[i];
      int j = i - 1;
      for (; j >= 0; j--)
      {
         if (arr[j] > key)
         {
            arr[j + 1] = arr[j];
         }
         else
            break;
      }
      arr[j + 1] = key;
   }
   for (int i = 0; i < 10; i++)
      cout << arr[i] << " ";
   cout << endl;

   // now using while loop
   //    int key = arr[i];
   //    int j = i - 1;

   //    while (key < arr[j] && j >= 0)
   //    {
   //       arr[j + 1] = arr[j];
   //       j--;
   //    }
   //    arr[j + 1] = key;
   // }
   // for (int i = 1; i < 10; i++)
   // {
   //    for (int j = 0; j < 10 - i; j++)
   //    {
   //       if (arr[j] > arr[j + 1])
   //       {
   //          swap(arr[j], arr[j + 1]);
   //       }
   //    }
   // }

   // for (int i = 0; i < 10; i++)
   //    cout << arr[i] << " ";
   // cout << endl;
   //
   //
   //
   //

   // insertion sort practice

   // for (int i = 1; i < 10; i++)
   // {
   //    int key = arr[i];
   //    int j = i - 1;
   //    for (; j >= 0; j--)
   //    {
   //       if (key < arr[j])
   //       {
   //          arr[j + 1] = arr[j];
   //       }
   //       else
   //          break;
   //    }
   //    arr[j + 1] = key;
   //    //using while loop
   //    int j = i - 1;
   //    while (j >= 0 && arr[j] > key)
   //    {
   //       arr[j + 1] = arr[j];
   //       j--;
   //    }
   //    arr[j + 1] = key;
   // }

   // USING BUBBLE SORT
   // for (int i = 0; i < 10 - 1; i++)
   // {
   //    for (int j = 0; j < 10 - i - 1; j++)
   //    {
   //       if (arr[j] > arr[j + 1])
   //          swap(arr[j], arr[j + 1]);
   //    }
   // }

   // selection sort
   // for (int i = 0; i < 10 - 1; i++)
   // {
   //    int min = i;
   //    for (int j = i + 1; j < 10; j++)
   //    {
   //       if (arr[j] < arr[min])
   //       {
   //          min = j;
   //       }
   //    }
   //    swap(arr[min], arr[i]);
   // }

   // cout << "After sorting" << endl;
   // for (int i = 0; i < 10; i++)
   //    cout << arr[i] << " ";
   // cout << endl;
   // question 2.
   //  if (n % 2 == 0)
   //  {
   //     float mid = (arr[n / 2 - 1] + arr[n / 2])/2;
   //     cout << "mid is " << mid;
   //  }
   //  else{
   //     cout << "mid is "<< arr[n/2+1];
   //  }
   // question 3
   // after sorted
   // int diff = INT_MAX;
   // for (int i = 0; i < n - 1; i++)
   // {
   //    if (arr[i + 1] - arr[i] < diff)
   //       diff = arr[i + 1] - arr[i];
   // }
   // cout << diff;
   // question 4
   // for (int i = 0; i < n - 1; i++)
   // {
   //    int min = i;
   //    for (int j = i + 1; j < n; j++)
   //    {
   //       if (arr[j]*arr[j] < arr[min]*arr[min])
   //       {
   //          min = j;
   //       }
   //    }
   //    swap(arr[min], arr[i]);
   // }

   // cout << "After sorting" << endl;
   // for (int i = 0; i < n; i++)
   //    cout << arr[i] << " ";
   // cout << endl;
   // question 5
   // string arr[] = {"apple", "bat", "carrot", "dog"};
   // int n = sizeof(arr) / sizeof(string);
   // cout << n << endl;
   // //cout << arr[0].length() << endl;
   // for (int i = 0; i < n - 1; i++)
   // {
   //    int min = i;
   //    for (int j = i + 1; j < n; j++)
   //    {
   //       if (arr[j].length() < arr[min].length())
   //       {
   //          min = j;
   //       }
   //    }
   //    swap(arr[min], arr[i]);
   // }
   // for (int i = 0; i < n; i++)
   //    cout << arr[i] << " ";
   // cout << endl;
   // question 6

   // int arr[10] = {5, 554, 4, 77, 799, 39, 22, 98, 54, 87};
   // int arr[] = {4,3,2,1};
   // int n = sizeof(arr) / sizeof(int);
   // for (int i = 0; i < n; i++)
   //    cout << arr[i] << "  ";
   // cout << endl;
   // for (int i = 0; i < n - 1; i = i + 2)
   // {
   //    int min = i;
   //    for (int j = i + 2; j < n; j = j + 2)
   //    {
   //       if (arr[j] < arr[min])
   //       {
   //          min = j;
   //       }
   //    }
   //    swap(arr[min], arr[i]);
   // }

   // for (int i = 1; i < n-2; i = i + 2)
   // {
   //    int min2 = i;

   //    for (int j = i + 2; j < n; j = j + 2)
   //    {
   //       if (arr[j] > arr[min2])
   //       {
   //          min2 = j;
   //       }
   //    }
   //    swap(arr[min2], arr[i]);
   // }
   // for (int i = 0; i < n; i++)
   //    cout << arr[i] << "  ";
   // cout << endl;
   // question 7
   //
   //
   //
   //
   // int arr[] = {1, 9, 3, 10, 4, 5, 2};
   // int arr[]={1,2,0,4,5,6,7,8,9};
   // int n = sizeof(arr) / sizeof(int);
   // int m = 1;
   // for (int i = 0; i < n - 1; i++)
   // {
   //    int min = i;
   //    for (int j = i + 1; j < n; j++)
   //    {
   //       if (arr[j] < arr[min])
   //       {
   //          min = j;
   //       }
   //    }
   //    swap(arr[min], arr[i]);
   // }
   // for (int i = 0; i < n; i++)
   //    cout << arr[i] << "  ";
   // cout << endl;
   // for (int i = 0; i < n; i++)
   // {
   //    int j = i;
   //    int value = 1;
   //    while (arr[j + 1] == arr[j] + 1)
   //    {
   //       value++;
   //       j++;
   //    }
   //    if (value > m)
   //    {
   //       m = value;
   //    }
   // }
   // cout << m << endl;

   //
   //
   //
   //
   // // question 8
   // int arr[] = {4, 3, 1, 6, 1, 3, 4, 4};
   // int n = sizeof(arr) / sizeof(int);
   // int arr2[n];
   // for (int i = 0; i < n - 1; i++)
   // {
   //    int min = i;
   //    for (int j = i + 1; j < n; j++)
   //    {
   //       if (arr[j] < arr[min])
   //       {
   //          min = j;
   //       }
   //    }
   //    swap(arr[min], arr[i]);
   // }
   // int max = 1;
   // for (int i = 0; i < n; i++)
   // {
   //    int count = 1;
   //    int j = i;
   //    while (j < n - 1)
   //    {
   //       if (arr[j] == arr[j + 1])
   //       {
   //          count++;
   //       }
   //       if (count > max)
   //       {
   //          max = count;
   //       }
   //       j++;
   //    }
   // }

   // for (int i = 0; i < n; i++)
   //    cout << arr[i] << "  ";
   // cout << endl;

   // question 9
   // int a[] = {1, 16, 13, 14, 4};
   // int b[] = {15, 12, 5, 3, 7};
   // int n = sizeof(a) / sizeof(int);
   // int m = sizeof(b) / sizeof(int);
   // int x = n+m;
   // int arr[n + m];
   // int i = 0;
   // for (; i < n; i++)
   // {
   //    arr[i] = a[i];
   // }
   // for (int j = 0; j < m; j++)
   // {
   //    arr[i + j] = b[j];
   // }
   // for (int i = 0; i < x ; i++)
   // {
   //    int min = i;
   //    for (int j = i + 1; j < x; j++)
   //    {
   //       if (arr[j] < arr[min])
   //       {
   //          min = j;
   //       }
   //    }
   //    swap(arr[min], arr[i]);
   // }

   // for (int i = 0; i < x; i++)
   //    cout << arr[i] << "  ";
   // cout << endl;
   //
   //
   //
   // question 10
   return 0;
}

// #include <iostream>
// using namespace std;

// void frequencySort(int arr[], int n) {
//     int freq[1000] = {0};  // Frequency array (assuming values are < 1000)

//     // Step 1: Count occurrences of each element
//     for (int i = 0; i < n; i++)
//         freq[arr[i]]++;

//     // Step 2: Sort array manually (Nested Loop)
//     for (int i = 0; i < n ; i++) {
//         for (int j = i ; j < n; j++) {
//             if (freq[arr[j]] > freq[arr[i]] ||
//                (freq[arr[j]] == freq[arr[i]] && arr[j] < arr[i])) {
//                 swap(arr[i], arr[j]);  // Swap elements
//             }
//         }
//     }

//     // Step 3: Print sorted array
//     for (int i = 0; i < n; i++)
//         cout << arr[i] << " ";

//     cout << endl;
// }

// int main() {
//     int arr[] = {4, 3, 1, 6, 1, 3,3,3, 4, 4,4,4};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     frequencySort(arr, n);

//     return 0;
// }
