#include <stdio.h>
#include <ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) { stack[++top] = x; }
char pop() { return stack[top--]; }

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isRightAssociative(char op) {
    return op == '^';
}

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, k = 0;
    char ch;

    while ((ch = infix[i]) != '\0') {

        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (stack[top] != '(')
                postfix[k++] = pop();
            pop();
        }
        else {  
            // Operator case
            while (top != -1 &&
                   precedence(stack[top]) > precedence(ch) ||

                  (precedence(stack[top]) == precedence(ch) &&
                   !isRightAssociative(ch))) {

                postfix[k++] = pop();
            }
            push(ch);
        }

        i++;
    }

    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix: %s\n", postfix);
    return 0;
}
