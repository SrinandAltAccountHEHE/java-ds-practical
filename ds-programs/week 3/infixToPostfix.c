#include <stdio.h>
#include <ctype.h>

char operator_stack[20];
int top = -1;

void push(char operator) {
  operator_stack[++top] = operator;
}

int pop() {
  return top == -1 ? top : operator_stack[top--];
}

int priority(char operator) {
  if (operator== '+' || operator== '-')
    return 1;
  if (operator== '*' || operator== '/')
    return 2;
  return 0;
}

int main() {
  char infix_expression[20];

  printf("Enter the infix expression");
  scanf("%s", infix_expression);

  char *infix_expression_pointer = infix_expression;

  while (*infix_expression_pointer != '\0') {
    const char operator = *infix_expression_pointer;

    if (isdigit(operator))
      printf("%c", operator);

    else if (operator == '(')
      push(operator);

    else if (operator == ')') {
      while (operator_stack[top] != '(')
        printf("%c", pop());

      pop();
    } 
    else {
      while (priority(operator_stack[top]) >= priority(operator)) 
        printf("%c", pop());
      
      push(operator);
    }

    infix_expression_pointer++;
  }

  while (top > -1) 
    printf("%c", pop());

  printf("\n");
}
