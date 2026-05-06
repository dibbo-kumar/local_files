#include <stdio.h>
int a = 2;
int b = 3;
void reverse(int b)
{
    b = b + a;
    printf("\nrev:%d and %d", a, b);
}
int main()
{
    a = 10;
    printf("\nmain1 :%d", a);
    reverse(a);
    printf("\nmain :%d %d", a, b);
    return 0;
}