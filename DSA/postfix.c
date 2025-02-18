#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 10
int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = value;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        int value = stack[top];
        top--;
        return value;
    }
}

int evaluatePostfix(char* expression) {
    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            push(expression[i] - '0');
        } else {
            int operand2 = pop();
            int operand1 = pop();
            switch (expression[i]) {
                case '+':
                    push(operand1 + operand2);
                    break;
                case '-':
                    push(operand1 - operand2);
                    break;
                case '*':
                    push(operand1 * operand2);
                    break;
                case '/':
                    push(operand1 / operand2);
                    break;
            }
        }
    }
    return pop();
}
int main() {
    char expression[20];
    printf("Enter the postfix expression: ");
    scanf("%s", expression);
    int result = evaluatePostfix(expression);
    printf("The result of the given expression %s is : %d\n", expression, result);
    return 0;
}