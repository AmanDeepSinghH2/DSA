#include <stdio.h>
#define size 10
int top=-1;
int stack[size];
void push(int item){
    if(top==size-1){
        printf("Stack is full");
        return;
    }
    top++;
    stack[top]=item;
}
int pop(){
    if(top==-1){
        printf("stack is empty");
        return;
    }
    int item=stack[top];
    top--;
    return item;
}

void display()
{
    int i;
    for(i=top;i>=0;i--){
        printf("%d",stack[i]);
        printf("\n");
    }
}

int main(){
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
    return 0;
}
