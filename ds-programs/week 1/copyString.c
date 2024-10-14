#include <stdio.h>
#include <string.h>

int main() {
  char str1[100];
  char str2[100];

  printf("Enter string 1");
  scanf("%s", str1);

  printf("Enter string 2");
  scanf("%s", str2);

  strcpy(str1, str2);
  printf("%s", str1);



}
