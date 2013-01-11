#include <stdio.h>
#include <math.h>

int gcd(int x,int y){if(y)return gcd(y,x%y);return x;}

int search(int n,double sqrt_p,double (*f)(double)){
  int i=1,j,r=0,s=0;
  double gosa=10000,x,g;
  for(;i<=n;i++){ /*分母が1からnまで*/
    if((j=(int)f(sqrt_p*i))>n)break; /*分子の近似値がnよりも大きくなったら終了*/
    g=(x=(double)j/i-sqrt_p)*x; /*その近似値で誤差を評価する*/
    if(g<gosa&&gcd(j,i)==1){gosa=g;r=j;s=i;} /*分子が小さい方から評価しているので約分は必要ない、と思ったら誤差死しているようなのでgcd判定は必要w*/
  }
  return r*20000+s;
}

int main(){
  int n,p,x,y;
  double sqrt_p;
  while(scanf("%d%d",&p,&n),p){
    sqrt_p=sqrt(p);
    x=search(n,sqrt_p,floor);
    y=search(n,sqrt_p,ceil);
    printf("%d/%d %d/%d\n",y/20000,y%20000,x/20000,x%20000);
  }
  return 0;
}