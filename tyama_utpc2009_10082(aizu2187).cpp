#include <cstdio>
#include <algorithm>
int a[9],b[9];
int main(){
  int i,j,s,t,g;
  double x=362880;
  for(i=0;i<9;i++)scanf("%d",a+i);
  for(i=0;i<9;i++)scanf("%d",b+i);
  for(g=i=0;i<x;i++){
    for(s=t=j=0;j<9;j++)
      if(a[j]>b[j])s+=a[j]+b[j];else t+=a[j]+b[j];
    if(s>t)g++;
    std::next_permutation(b,b+9);
  }
  printf("%.5f %.5f\n",g/x,(x-g)/x);
  return 0;
}