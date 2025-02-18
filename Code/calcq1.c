#include <stdio.h>
int main()
{
    int n1, n2, sum, dif, pro, mod;
    float div;
    int n;
    printf("enter your option:");
    scanf("%d", &n);
    printf("enter the values:");
    scanf("%d %d", &n1, &n2);
    switch (n)
    {
    case 1:
        sum = n1 + n2;
        printf("the sum is:%d", sum);
        break;
    case 2:
        dif = n1 - n2;
        printf("the difference is: %d", dif);
        break;
    case 3:
        pro = n1 * n2;
        printf("the product is: %d", pro);
        break;
    case 4:
        div = (float)n1 / (float)n2;
        printf("the result is:", div);
        break;
    case 5:
        mod = n1 % n2;
        printf("the rem is: %d", mod);
        break;
    }
    return 0;
}
