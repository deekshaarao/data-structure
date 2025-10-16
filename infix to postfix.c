#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 20

typedef struct {
    int top;
    char data[SIZE];
} STACK;

void push(STACK *s, char item) {
    if (s->top >= SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    s->data[++(s->top)] = item;
}

char pop(STACK *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        return '\0';
    }
    return s->data[(s->top)--];
}

int precede(char symbol) {
    switch (symbol) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

void infixtopostfix(STACK *s, char infix[SIZE]) {
    int i, j = 0;
    char symbol, postfix[SIZE], temp;

    for (i = 0; infix[i] != '\0'; i++) {
        symbol = infix[i];

        if (isalnum(symbol)) {
            postfix[j++] = symbol;
        } else {
            switch (symbol) {
                case '(':
                    push(s, symbol);
                    break;

                case ')':
                    temp = pop(s);
                    while (temp != '(') {
                        postfix[j++] = temp;
                        temp = pop(s);
                    }
                    break;

                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                    while (s->top != -1 && precede(s->data[s->top]) >= precede(symbol) && s->data[s->top] != '(') {
                        postfix[j++] = pop(s);
                    }
                    push(s, symbol);
                    break;
            }
        }
    }

    while (s->top != -1) {
        postfix[j++] = pop(s);
    }

    postfix[j] = '\0';
    printf("\nPostfix expression is: %s\n", postfix);
}

int main() {
    char infix[SIZE];
    STACK s;
    s.top = -1;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixtopostfix(&s, infix);

    return 0;
}
