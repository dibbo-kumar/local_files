#include <stdio.h>
#include <string.h>
int a, c;
float b;
int fun1(float x);
void fun2(int *x, float y);

void main()
{
   a = 25;
   b = fun1(a);
   fun2(&a, b);

   printf("a = %f, b = %f\n", a, b);
}
int fun1(float x)
{
   c = x + a;
   fun2(&c, b);
   return c;
}
void fun2(int *x, float y)
{
   *x *= 2;
   y = a;
}