#include <stdio.h>
#include <math.h>
int main()
{
    int n = 5;
    int ans = 0;
    int i = 0;
    while (n != 0)
    {
        int digit = n % 2;

        ans = (digit * pow(10, i)) + ans;
        n = n / 2;
        i++;
    }
    // printf("%d ", n);
    printf("%d", ans);
    return 0;
}