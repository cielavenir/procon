#include <math.h>

//(1+「2以上sqrt(n)未満」まででnを割り切った数i+n/iの全て)と(nが平方数ならsqrt(n)、さもなくば0)の和
long long solve(long long n){
  long long sum=1;
  int i=2;
  double s=sqrt(n);
  if(n<6)return -1;
  for(;i<s;i++){
    if(n%i==0)sum += i+n/i;
  }
  if(floor(s)==s)sum+=s;
  return sum-n;
}

int main(){
  long long n,r;
  scanf("%lld",&n);
  r=solve(n);
  if(r<0)puts("Deficient");
  if(r==0)puts("Perfect");
  if(r>0)puts("Abundant");
  return 0;
}