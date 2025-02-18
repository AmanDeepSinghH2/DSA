#include <stdio.h>
int main()
{
    int a,b,c,d,r1,r2;
    printf("enter the values of coeffecients 'a','b','c': ");
    scanf(" %d %d %d",&a,&b,&c);
    d=pow(b,2)-4*a*c;
    printf("the determinant is : %d\n",d);
    r1=((-1)*b+pow(d,0.5))/2;
    r2=((-1)*b-pow(d,0.5))/2;
    printf("the 1st root of the equation is: %d\n",r1);
    printf("the 2nd root of the equation is: %d\n",r2);
    return 0;
}
