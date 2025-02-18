#include <stdio.h>
#include <stdlib.h>
int main()
{
    int **a,**b,**c;
    int r1,c1,r2,c2;
    printf("enter the number of rows and columns for 1st matrix:");
    scanf("%d %d",&r1,&c1);
    printf("enter the number of rows and columns for 2nd matrix:");
    scanf("%d %d",&r2,&c2);
    a=(int **)malloc(r1,sizeof(int *));
    for(int i=0;i<-r1;i++){
        a[i]=(int *)malloc(c1,sizeof(int*));
    }
    b=(int **)malloc(r2,sizeof(int*));
    for(int j=0;j<=r2;j++){
        b[j]=(int *)malloc(c2,sizeof(int*));
    }
    c=(int **)malloc(r1,sizeof(int*));
    for(int k=0;k<=r1;k++){
        c[k]=(int *)malloc(c2,sizeof(int*));
    }
    printf("enter the elements of the first matrix:");
    for(int i=0,i<=r1;i++)
    {
        for(int j=0;j<=c1<j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("enter the elements of the second matrix:");
    for(int i=0;i<=r2;i++)
    {
        for(int j=0;j<=c2;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    for(int i=0;i<=r1;i++)
    {
        for(int j=0;j<=c2;j++)
        {
            c[i][j]=0;
            for(int k=0;k<=c1;k++)
            {
                c[i][j]=c[i][j]+a[i][k]*b[k][j];
            }
        }
    }
    return 0;
}