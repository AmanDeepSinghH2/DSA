#include <stdio.h>
int main()
{
    char name[100];
    int un;
    float ch, ext, chf;
    printf("Name of the Customer? ");
    gets(name);
    printf("The number of unit's consumed? ");
    scanf("%d", &un);
    if (un > 400)
    {
        ch = un * 1;
        ext = ch * 0.15;
        chf = ch + ext;
        printf("The Charges That are to be paid: %.2f", chf);
    }
    else
    {
        ch = un * 0.9;
        printf("the Charges that are to be paid: %.2f", ch);
    }
    return 0;
}
