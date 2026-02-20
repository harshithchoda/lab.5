//A. Implementation of stack using array

#include <stdio.h>
#define MAX 5

int main() {
    int stack[MAX], top = -1;
    int choice, value, i;

    while (1) {
        printf("\n1.Push  2.Pop  3.Peek  4.Display  5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (top == MAX - 1)
                printf("Stack Overflow!\n");
            else {
                printf("Enter value: ");
                scanf("%d", &value);
                stack[++top] = value;
                printf("%d pushed\n", value);
            }
        }

        else if (choice == 2) {
            if (top == -1)
                printf("Stack Underflow!\n");
            else
                printf("%d popped\n", stack[top--]);
        }

        else if (choice == 3) {
            if (top == -1)
                printf("Stack is empty\n");
            else
                printf("Top = %d\n", stack[top]);
        }

        else if (choice == 4) {
            if (top == -1)
                printf("Stack is empty\n");
            else {
                printf("Stack: ");
                for (i = top; i >= 0; i--)
                    printf("%d ", stack[i]);
                printf("\n");
            }
        }

        else if (choice == 5)
            break;

        else
            printf("Invalid choice!\n");
    }

    return 0;
}
