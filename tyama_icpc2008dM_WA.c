#include <stdio.h>
int main(){
  const int magic=2029; /* they say... */
  int x,c=0;
  while(scanf("%d",&x),x){
    if(x==magic)fprintf(stderr,"Err:same\n");
    printf(x<magic ? "smaller\n" : "larger\n");
    if(x<magic)c++;
  }
  fprintf(stderr,"%d\n",c);
  return 0;
}