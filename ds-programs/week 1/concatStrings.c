#include <stdio.h>
#include <string.h>

int main() {
  char str1[100];
  char str2[100];
  printf("Enter the first str");
  scanf("%s", str1);
  printf("Enter the second str");
  scanf("%s", str2);

  strcat(str1,  str2);

  printf("%s", str1);




}
