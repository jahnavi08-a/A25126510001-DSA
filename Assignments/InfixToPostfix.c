#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

void infixToPostfix(char infix[]) {
    char postfix[MAX];
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        // If operand, add directly to postfix
        if (isalnum((unsigned char)ch)) {
            postfix[j++] = ch;
        }

        // If '(', push to stack
        else if (ch == '(') {
            push(ch);
        }

        // If ')', pop until '('
        else if (ch == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            if (top != -1)
                pop(); // remove '('
        }

        // If operator
        else if (ch == '+' || ch == '-' ||
                 ch == '*' || ch == '/' || ch == '^') {

            while (top != -1 && peek() != '(' &&
                   (precedence(peek()) > precedence(ch) ||
                   (precedence(peek()) == precedence(ch) && ch != '^'))) {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix: %s\n", postfix);
}

int main() {
    char infix[MAX];

    printf("Enter infix expression: ");
    scanf("%99s", infix);

    infixToPostfix(infix);

    return 0;
}