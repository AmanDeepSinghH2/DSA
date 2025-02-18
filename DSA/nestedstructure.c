#include <stdio.h>
#include <stdlib.h>
struct s1{
    int a;
    int b;
};
struct s2{
    struct s1 s1;
    int c;
};
void details(struct s2 e)
{
    printf("enter a:");
    scanf("%d",&e.s1.a);
    printf("\nenter b:");
    scanf("%d",&e.s1.b);
    printf("\nenter c:");
    scanf("%d",&e.c);
    printf("\t\v\nall input stored in a b and c ");
}
int main()
{
    struct s2 s;
    details(&s);
    return 0;
}