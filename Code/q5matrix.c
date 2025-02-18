#include <stdio.h>
int main()
{
    int m, n, p, q, i, j;
    int a[i][j], b[i][j], c[i][j];
    printf("enter no. of rows and columns for mat a: \n");
    scanf("%d %d,&m,&n");
    printf("enter no. of rows and columns for mat b: \n");
    scanf("%d %d,&p,&q");
    if (n == p)
    {
        printf("Matrix multiplication is possible!!");
        printf("enter elements for a");
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }
        printf("enter elements for b");
        for (i = 0; i < p; i++)
        {
            for (j = 0; j < q; j++)
            {
                scanf("%d", &b[i][j]);
            }
        }
    }
    else
    {
        printf("multiplication not possible, try again");
        main();
    }
    printf("let's do matrix multiplication!");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < q; j++)
        {
            c[i][j] = a[i][j] * b[i][j];
            printf(c[i][j]);
        }
    }
    return 0;
}