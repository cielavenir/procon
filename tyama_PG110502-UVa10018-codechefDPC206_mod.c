//tyama070521reverse.c
#include <stdio.h>

inline unsigned reverse(unsigned u){
  unsigned ret=0;
  while(u){
    ret=(ret<<3)+(ret<<1)+u%10;
    u/=10;
  }
  return ret;
}

int main(){
  unsigned u,t;
  int n,count;

  scanf("%d", &n);
  for(;n;n--){
    scanf("%u", &u);
    count^=count;
    t=reverse(u);
    while(u^t){
      u+=t;
      t=reverse(u);
      count++;
    };
    printf("%d %u\n",count,u);
  }
  return 0;
}