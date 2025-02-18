#include <stdio.h>
int main()
{
    int n,num,flag=0;
    int a[n],i;
    printf("enter the size of the array: ");
    scanf("%d",&n);
    printf("enter elementsof the array: ");
    for(i=0;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter the element that you want to search: ");
    scanf("%d",&num);
    for(i=0;i<=n;i++)
    {
        if(num==a[i])
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        printf("element found at position %d",i+1);
    }
    else{
        printf("element not found!!");
    }
    return 0;
    
}