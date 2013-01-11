#include <math.h>

//約数の和は、1+「2以上sqrt(n)未満」まででnを割り切った数i+n/iの全て」+nが平方数ならsqrt(n)、で与えられる。
int kan(int n){
  int sum=1,i=2;
  double s=sqrt(n);
  if(n<6)return -1;
  for(;i<s;i++){
    if(n%i==0)sum += i+n/i;
  }
  if(floor(s)==s&&n%(int)s==0)sum+=s;
  return sum-n;
}

int main(){
  int n,r;
  while(1){
    scanf("%d",&n);
    if(n==0)return 0;
    r=kan(n);
    if(r<0)printf("deficient number\n");
    if(r==0)printf("perfect number\n");
    if(r>0)printf("abundant number\n");
  }
}