#include <stdio.h>
#include <ctype.h>

int stack[20];
int top = -1;

void push(int x) {
  stack[++top] = x;
}

int pop() {
  return stack[top--];
}

int main() {
  char exp[20];
  int n1, n2;

  printf("Enter the postfix expression");
  scanf("%s", exp);

  char *e = exp;

  while (*e != '\0')  {

    if (isdigit(*e)) {
      push(*e-48);
    } else {

      n1 = pop();
      n2 = pop();
      char opr = *e;

      switch (opr) {
        case '+':
          push(n1+n2);
          break;

        case '-':
          push(n2-n1);
          break;

        case '*':
          push(n1*n2);
          break;

        case '/':
          push(n2/n1);
          break;
      }
    }

    e++;
  }

  printf("evaluated postfix expression: %d", pop());
}
