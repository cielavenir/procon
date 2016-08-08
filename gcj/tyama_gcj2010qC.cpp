//if compiled using -O2, this can solve large in 2mins.
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
  long long s;
  int t,u=1,r,k,l,n,x,c;
  for(scanf("%d",&t);u<=t;u++){
    vector<int> g;
    for(scanf("%d%d%d",&r,&k,&n),s=0;n;g.push_back(x),n--)scanf("%d",&x),s+=x;
    if(s<=k){printf("Case #%d: %lld\n",u,s*r);continue;}
    for(s=c=0;r;r--){
      for(l=k;l>=g[c];c=c==(g.size()-1)?0:(c+1))l-=g[c],s+=g[c];
      //fprintf(stderr,"---%d\r",r);
    }
    printf("Case #%d: %lld\n",u,s);
  }
}