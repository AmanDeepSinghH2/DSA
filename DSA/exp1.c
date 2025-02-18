#include <stdio.h>
#include <stdlib.h>
struct time {
    int hour;
    int min;
    int sec;
};
int main(){
    struct time t1,t2;
    int h, m, s;
    //1st
    printf("enter hour: ");
    scanf("%d",&t1.hour);
    printf("\venter minutes: ");
    scanf("%d",&t1.min);
    printf("\venter seconds:");
    scanf("%d",&t1.sec);
    printf("\v");
    //2nd
    printf("enter hour: ");
    scanf("%d",&t2.hour);
    printf("\venter minutes: ");
    scanf("%d",&t2.min);
    printf("\venter seconds:");
    scanf("%d",&t1.sec);
    h=t1.hour+t2.hour;
    m=t1.min+t2.min;
    s=t1.sec+t2.sec;
    printf(h,m,s);
    return 0;
}