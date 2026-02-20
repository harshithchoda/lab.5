//B. Program to convert infix expression to postfix using stack

#include <stdio.h>
#include <ctype.h>
#define MAX 100

int main() {
    char infix[MAX], postfix[MAX], stack[MAX];
    int top = -1, i = 0, j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    while (infix[i] != '\0') {
        char ch = infix[i];

        if (isalnum(ch))
            postfix[j++] = ch;

        else if (ch == '(')
            stack[++top] = ch;

        else if (ch == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = stack[top--];
            top--;
        }

        else {
            int prec;
            if (ch == '+' || ch == '-') prec = 1;
            else if (ch == '*' || ch == '/') prec = 2;
            else if (ch == '^') prec = 3;
            else prec = 0;

            while (top != -1) {
                int stackPrec;
                if (stack[top] == '+' || stack[top] == '-') stackPrec = 1;
                else if (stack[top] == '*' || stack[top] == '/') stackPrec = 2;
                else if (stack[top] == '^') stackPrec = 3;
                else stackPrec = 0;

                if (stackPrec >= prec)
                    postfix[j++] = stack[top--];
                else
                    break;
            }
            stack[++top] = ch;
        }
        i++;
    }

    while (top != -1)
        postfix[j++] = stack[top--];

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);
    return 0;
}
