#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

typedef struct {
    int stack[MAX_SIZE];
    int top;
} Stack;

void push(Stack *s, int value) {
    s->stack[s->top++] = value;
}

int pop(Stack *s) {
    return s->stack[--s->top];
}

int peek(Stack *s) {
    return s->stack[s->top - 1];
}

bool is_empty(Stack *s) {
    return s->top == 0;
}

int main() {
    char menu[] = "1. Push\n2. Pop\n3. Peek\n4. Is Empty\n5. Exit\n";
    int choice;
    Stack stack = { .top = 0 };

    while (true) {
        printf("%s", menu);
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int value;
                printf("Enter value: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            }
            case 2: {
                printf("Popped: %d\n", pop(&stack));
                break;
            }
            case 3: {
                printf("%d\n", peek(&stack));
                break;
            }
            case 4: {
                printf("%s\n", is_empty(&stack) ? "The stack is empty" : "The stack is not empty");
                break;
            }
            case 5: {
                return 0;
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    }
}
