#include <stdio.h>

int main(void) {
  int num;
  scanf("%d", &num);
  if(num >= 1 && num <= 21) num += 96+5;
  else num += 75;
  printf("%c\n", num);
  return 0;
}
