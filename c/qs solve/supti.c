#include <stdio.h>

int isPalindrome(int num)
{
    int original = num;
    int reversed = 0;
    int count = 0;
    int sum = 0;
    while (num > 0)
    {
        int digit = num % 10;
        if (count % 2 == 0)
            sum = sum + digit;
        reversed = reversed * 10 + digit;
        num /= 10;
        count++;
    }
    if (reversed == original)
        return sum;
    else
        return 0;
}
int main()
{
    int n, i;
    printf("enter a positive integer\n");
    scanf("%d", &n);
    int f = 0;
    int s = isPalindrome(n);
    int g = 0;
    if (isPalindrome(n) != 0)
    {
        printf("%d is a palindrome\n", n);
        g = 1;
    }
    else
    {
        printf("%d is not a palindrome\n", n);
    }
    if (s % 2 == 1 && g == 1)
    {
        printf("even indexed sum is odd\n ");
        f = 1;
    }
    else if (g == 1)
    {
        printf("even indexed sum is not odd\n ");
    }
    if (isPalindrome(n) != 0 && f == 1)
        printf("special number");
    else
        printf("not special");
    return 0;
}