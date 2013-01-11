#include <stdio.h>

inline unsigned reverse(unsigned u){
  unsigned ret=0;
  while(u){
    ret=(ret<<3)+(ret<<1)+u%10;
    u/=10;
  }
  return ret;
}

int main(int argc, char **argv){
  unsigned u,t;
  int n,count;
  FILE *f=fopen(argv[1],"r");
  for(;~fscanf(f,"%u",&u);n--){
    count^=count;
    t=reverse(u);
    while(u^t){
      u+=t;
      t=reverse(u);
      count++;
    };
    printf("%d %u\n",count,u);
  }
  fclose(f);
  return 0;
}