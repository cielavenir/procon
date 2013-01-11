#include <math.h>
main(){
  int n;
  double d;
  for(;~scanf("%d%lf",&n,&d);){
    d+=(n-1)*n/2;
    printf("%d\n",(int)ceil((sqrt(8*d+1)-1)*0.5));
  }
  return 0;
}