#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main(){

    int a[10][10],b[10][10],c[10][10],r1,c1,r2,c2,i,j,k,sum=0;
    printf("enter the rows and collumns for a:");
    scanf("%d %d",&r1,&c1);
    printf("enter the rows and collumns for b:");
    scanf("%d %d",&r2,&c2);
    a=(int**)malloc(sizeof(int*)*r1);
    for(i=0;i<=r1;i++){
        a=(int*)malloc(sizeof(in*)*c1);
    }
    b=(int**)malloc(sizeof(int*)*r2);
    for(i=0;i<=r2;i++){
        b=(int*)malloc(sizeof(int*)*c2);
    }
    c=(int**)malloc(sizeof(int*)*r1);
    for(i=0;i<=r1;i++)
    {
        c=(int*)malloc(sizeof(int*)*c2);
    }
    printf("Enter values for A:");
    for (i=0;i<=r1;i++)
    {
        for(j=0;j<=c1;j++){
            scanf("%d",&a[i][j];)
        }
    }
    printf("enter values for B:");
    for(i=0;i<=r2;i++)
    {
        for(j=0;j<=c2;j++){
            scanf("%d",&b[i][j]);
        }
    }
    for(i=0;i<=r1;i++){
        for(j=0;j<=c2;j++){
            c[i][j]=0;
        }
    }
    for (i=0;i<=r1;i++){
        for(j=0;j<=c1;j++){
            for(k=0;k<=a1;k++){
                c[i][j]=c[i][j]+a[i][k]*b[k][j];
            }
        }
    }
    return 0;

}