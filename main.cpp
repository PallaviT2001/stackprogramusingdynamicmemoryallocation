#include <stdio.h>
#include <stdlib.h>

int *stack;
int top = -1;
int Max;

void push(int value)
{
    if (top >=Max - 1)
    {
        printf("Stack overflow %d.\n", value);
    }
    else
    {
        stack[++top] = value;
        printf("%d pushed onto the stack.\n", value);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("%d Popped from the stack.\n", stack[top--]);
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack elements are: ");
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, value;

    printf("Enter the maximum size of the stack: ");
    scanf("%d", &Max);

    stack = (int *)malloc(Max * sizeof(int));

    if (stack == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter value to Push: ");
            scanf("%d", &value);
            push(value);
        }
        else if (choice == 2)
        {
            pop();
        }
        else if (choice == 3)
        {
            display();
        }
        else if (choice == 4)
        {
            printf("Exiting program.\n");
            break;
        }
        else
        {
            printf("Invalid choice.\n");
        }
    }

    free(stack);

    return 0;
}
