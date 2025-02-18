#include<stdio.h>
int main()
{
    int r1,c1,r2,c2;
    printf("enter rows and columns for 1st matrix:");
    scanf("%d %d",&r1,&c1);
    printf("enter rows and columns for 2nd matrix:");
    scanf("%d %d",&r2,&c2);
    int a[r1][c1],b[r2][c2],c[r1][c2];
    printf("enter eleements for the 1st matrix:");
    for (int i=0;i<=r1-1;i++)
    {
        for(int j=0;j<=c1-1;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("enter elements for 2nd matrix:");
    for(int i=0;i<=r2-1;i++)
    {
        for(int j=0; j<=c2-1;j++){
            scanf("%d",&b[i][j]);
        }
    }
    for(int i=0;i<=r1-1;i++)
    {
        for (int j=0;j<=c2-1;j++)
        {
            c[i][j]=0;
            for(int k=0;k<=c1-1;k++)
            {
                c[i][j]=c[i][j]+a[i][k]*b[k][i];
            }
        }
    }
    printf("the resultis:");
    for(int i=0;i<=r1-1;i++)
    {
        for(int j=0;j<=c2-1;j++)
        {
            printf("%d",c[i][j]);
        }
        printf("\n");
    }
    return 0;
}