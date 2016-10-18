#include <math.h>

//(1+「2以上sqrt(n)未満」まででnを割り切った数i+n/iの全て)と(nが平方数ならsqrt(n)、さもなくば0)の和
int solve(int n){
  int sum=1,i=2;
  double s=sqrt(n);
  if(n<6)return -1;
  for(;i<s;i++){
    if(n%i==0)sum += i+n/i;
  }
  if(floor(s)==s)sum+=s;
  return sum-n;
}

int main(){
  int n,r;
  for(;scanf("%d",&n),n;){
    r=solve(n);
    if(r<0)puts("deficient number");
    if(r==0)puts("perfect number");
    if(r>0)puts("abundant number");
  }
  return 0;
}