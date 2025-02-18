#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *p;
    p=(int*)malloc(5*sizeof(int));
    p[0]=10;
    p[1]=20;
    p[2]=30;
    p[3]=40;
    p[4]=50;
    for(int i=0;i<5;i++)
    {
        printf("%d ",p[i]);
    }
    int *a;
    a=(int*)calloc(5,sizeof(int));
    a[0]=10;
    a[1]=20;
    a[2]=30;
    a[3]=40;
    a[4]=50;
    for(int i=0;i<5;i++)
    {
        printf("%d ",a[i]);
    }
    
    int *b;
    b=(int*)realloc(a,10*sizeof(int));
    b[0]=10;
    b[1]=20;
    b[2]=30;
    b[3]=40;
    b[4]=50;
    b[5]=60;
    b[6]=70;
    b[7]=80;
    b[8]=90;
    b[9]=100;
    for(int i=0;i<10;i++)
    {
        printf("%d ",b[i]);
    }
    return 0;
}