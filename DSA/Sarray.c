#include <stdio.h>
#include <stdlib.h>
struct person {
    char name[20];
    int age;
};
int main(){
    int n;
    printf("Enter how many records u want to store:");
    scanf("%d",&n);
    struct person p[n];
    for(int i=1;i<=n;i++){
        printf("Enter name of person: ");
        scanf("%s",p[i].name);
        printf("Enter age: ");
        scanf("%d",&p[i].age);
    }
    return 0;
}