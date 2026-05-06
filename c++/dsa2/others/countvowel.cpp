#include <iostream>
#include <string>
using namespace std;

// Function to check if a character is a vowel
bool isVowel(char d)
{
    char c = tolower(d);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

// Divide & Conquer function to count vowels
int countVowelsDC(const string &s, int left, int right)
{
    // Base case: single character
    if (left == right)
    {
        return isVowel(s[left]) ? 1 : 0;
    }

    int mid = left + (right - left) / 2;

    // Conquer left and right halves
    int leftCount = countVowelsDC(s, left, mid);
    int rightCount = countVowelsDC(s, mid + 1, right);

    // Combine
    return leftCount + rightCount;
}

int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    int totalVowels = countVowelsDC(str, 0, str.size() - 1);

    cout << "Total vowels = " << totalVowels << endl;

    return 0;
}
