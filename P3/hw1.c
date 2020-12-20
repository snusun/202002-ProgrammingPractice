#include <stdio.h>

int main(void) {
  int a, b;
  scanf("%d %d", &a, &b);
  int fst = b%10;
  int tenth = b/10;
  printf("%d\n%d\n%d\n", a*fst, a*tenth, a*b);
  return 0;
}