#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10000

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;
}

bool isEmpty(const Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, char value) {
    if (stack->top < MAX_SIZE - 1) {
        stack->data[++stack->top] = value;
        printf("Pushed: %c\n", value);
    } else {
        printf("Stack overflow\n");
    }
}

char pop(Stack *stack) {
    if (!isEmpty(stack)) {
        char poppedValue = stack->data[stack->top];
        stack->top--;
        printf("Popped: %c\n", poppedValue);
        return poppedValue;
    } else {
        printf("Stack underflow\n");
        return '\0'; // Return a sentinel value indicating underflow
    }
}

char peek(const Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top];
    } else {
        printf("Stack is empty\n");
        return '\0'; // Return a sentinel value indicating empty stack
    }
}

bool isValid(char *s)
{
    bool result = true;
    // int arraySize = sizeof(s)/sizeof(char);
    // printf("%d\n", sizeof(s));
    // printf("%d\n", arraySize);
    Stack sp;
    initialize(&sp);
    int i = 0;
    char temp = s[i];
    while ((temp == '(' || temp == ')' ||
           temp == '{' || temp == '}' ||
           temp == '[' || temp == ']') && result == true)
    {
        switch (temp)
        {
        case '(':
            push(&sp, temp);
            break;
        case '{':
            push(&sp, temp);
            break;
        case '[':
            push(&sp, temp);
            break;
        case ')':
            if (pop(&sp) != '(')
            {
                result = false;
            }
            break;
        case '}':
            if (pop(&sp) != '{')
            {
                result = false;
            }
            break;
        case ']':
            if (pop(&sp) != '[')
            {
                result = false;
            }
            break;
        default:
            printf("Default err");
            break;
        }
        i++;
        temp = s[i];
    }
    if(isEmpty(&sp)!= true){
        result = false;
    }
    return result;
}
int main()
{
    char s[20] = "(";
    bool result = isValid(s);
    if (result == true)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
}
