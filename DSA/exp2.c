#include <stdio.h>
#include <stdlib.h>
struct details{
    int rollno;
    int marks;
};
int main()
{
    struct details *d,d1;
    d=&d1;
    printf("Enter rollno: ");
    scanf("%d",&d->rollno);
    printf("enter marks: ");
    scanf("%d",&d->marks);
    return 0;
}