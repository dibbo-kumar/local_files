// // #include <iostream>
// // using namespace std;

// // bool isPowerOfFour(int n) {
// //     // Base cases
// //     if (n == 1) return true;   // 4^0 = 1
// //     if (n == 0 || n % 4 != 0) return false;

// //     // Recursive call
// //     return isPowerOfFour(n / 4);
// // }

// // int main() {
// //     int n;
// //     cout << "Enter a number: ";
// //     cin >> n;

// //     if (isPowerOfFour(n))
// //         cout << n << " is a power of 4." << endl;
// //     else
// //         cout << n << " is NOT a power of 4." << endl;

// //     return 0;
// // }
// #include <iostream>
// using namespace std;

// // Divide & Conquer Power Function
// long long power(long long a, long long b) {
//     if (b == 0) return 1;  // base case
//     if (b == 1) return a;

//     long long half = power(a, b / 2);

//     if (b % 2 == 0) 
//         return half * half;       // even exponent
//     else 
//         return a * half * half;   // odd exponent
// }

// int main() {
//     long long base, exp;
//     cout << "Enter base and exponent: ";
//     cin >> base >> exp;

//     cout << base << "^" << exp << " = " << power(base, exp) << endl;
//     return 0;
// }
