/*d. A calculator application internally stores arithmetic expressions in postfix format for
faster evaluation. Write a program to evaluate a given postfix expression using a stack.*/
#include <stdio.h>
#include <ctype.h>
#define MAX 100

int main() {
    char postfix[MAX];
    int stack[MAX];
    int top = -1, i = 0;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    while (postfix[i] != '\0') {
        char ch = postfix[i];

        if (isdigit(ch))
            stack[++top] = ch - '0';

        else {
            int b = stack[top--];
            int a = stack[top--];

            if (ch == '+') stack[++top] = a + b;
            else if (ch == '-') stack[++top] = a - b;
            else if (ch == '*') stack[++top] = a * b;
            else if (ch == '/') stack[++top] = a / b;
        }
        i++;
    }

    printf("Result = %d\n", stack[top]);
    return 0;
}
