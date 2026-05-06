#include <stdio.h>
int main()
{
    int b = 7;
    int a[5] = {8, 20, 30, 40, 50};
    int *p1, t, u, v, w;

    p1 = a;
    t = (*p1)++;
    u = *p1;
    v = *(p1)++;
    w = *(++p1);
    
    printf(" %d %d %d %d", t, u, v, w);
}