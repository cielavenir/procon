/* Reference: http://ja.wikipedia.org/wiki/%E5%A4%96%E6%8E%A5%E5%86%86 */
#include <math.h>
#include <stdio.h>
#define HYPOT(a1,a2,b1,b2) (sqrt( ((a1)-(b1))*((a1)-(b1))+((a2)-(b2))*((a2)-(b2)) ))

int main(){
  double a1,a2,b1,b2,c1,c2,a,b,c,s;
  while(1){
    if(scanf("%lf%lf%lf%lf%lf%lf",&a1,&a2,&b1,&b2,&c1,&c2)!=6)return 0;
    a=HYPOT(a1,a2,b1,b2);b=HYPOT(b1,b2,c1,c2);c=HYPOT(c1,c2,a1,a2);s=a+b+c;
    printf("%.2lf\n",2*3.141592653589793*(a*b*c)/sqrt(s*(s-2*a)*(s-2*b)*(s-2*c)));
  }
}