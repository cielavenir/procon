#include <cstdio>
#include <map>

int main(){
  int i,n,m,x,r;
  for(;scanf("%d%d",&n,&m),n;printf("%d\n",r)){
    std::map<int,int> M;
    for(i=0;i<n;i++)scanf("%d",&x),M[x]=1;
    for(i=r=0;i<m;i++)scanf("%d",&x),r+=M[x]?1:0;
  }
}