#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define SIZE 10

struct stack {
    int top;
    float data[SIZE];
};

typedef struct stack STACK;

void push(STACK *s, float item) {
    if (s->top >= SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->data[++(s->top)] = item;
}

float pop(STACK *s) {
    if (s->top < 0) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

float compute(float opr1, char symbol, float opr2) {
    switch (symbol) {
        case '+': return opr1 + opr2;
        case '-': return opr1 - opr2;
        case '*': return opr1 * opr2;
        case '/': return opr1 / opr2;
        case '^': return pow(opr1, opr2);
        default:
            printf("Invalid operator: %c\n", symbol);
            exit(1);
    }
}

float evaluatepostfix(STACK *s, char postfix[20]) {
    int i;
    float opr1, opr2, result;
    char symbol;

    for (i = 0; postfix[i] != '\0'; i++) {
        symbol = postfix[i];
        if (isdigit(symbol)) {
            push(s, symbol - '0');  // Convert char digit to float
        } else {
            opr2 = pop(s);
            opr1 = pop(s);
            result = compute(opr1, symbol, opr2);
            push(s, result);
        }
    }
    return pop(s);
}

int main() {
    char postfix[20];
    STACK s;
    s.top = -1;
    float result;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    result = evaluatepostfix(&s, postfix);
    printf("Result: %.2f\n", result);

    return 0;
}
