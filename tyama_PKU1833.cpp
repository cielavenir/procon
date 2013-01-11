//自前でPermutationしたらTLEなのにこれだと通る…STLスゴスw
#include <algorithm>
#include <cstdio>
int main(){
  int x,i,n,k,m[1024];
  scanf("%d",&x);
  for(;x;x--){
    scanf("%d%d",&n,&k);
    for(i=0;i<n;)scanf("%d",m+i++);
    for(;k;k--)std::next_permutation(m,m+n);
    for(i=0;i<n;i++)printf(i==n-1?"%d\n":"%d ",m[i]);
  }
}