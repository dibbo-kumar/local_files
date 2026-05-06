#include <stdio.h>
#include<string.h>
 int main ()
 {
     char str1[50],str2[50];
     int len1=0;

    scanf ("%s",str1);

    for (int i=0;str1[i]!='\0';i++){
        len1++;
    }
    int j=0;
    for (int i=len1-1;i>=0;j++,i++){
        str2[i]= str1[j];
    }
    printf ("%s",str2);



     return 0;
 }