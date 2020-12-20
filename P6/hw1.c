#include <stdio.h>
#include <math.h>

int main(void){
  int x1, y1, x2, y2, r1, r2;
  scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
  scanf("%d %d", &r1, &r2);
  double dis = sqrt(pow(x1-x2, 2)+pow(y1-y2, 2));
  double sum = r1+r2;
  double diff = sqrt(pow(r1-r2,2));
  if(dis == 0 && diff == 0) return 0;
  if(dis > sum || dis < diff){
    printf("교점이 없습니다.\n");
  }
  else if(dis == sum || dis == diff){
    printf("교점이 하나 입니다.\n");
  }
  else if(dis < sum || dis > diff){
    printf("교점이 두 개 입니다.\n");
  }
 return 0;
}