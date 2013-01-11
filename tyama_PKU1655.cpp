#include <cstdio>
#include <vector>
using namespace std;
vector<vector<int> >D;
int N,a,b;
int d(int c, int p){
  int s=1,ba=0,i=0,co;
  for(;i<D[c].size();i++)
    if(D[c][i]!=p){
      co=d(D[c][i],c),s+=co;
      if(ba<co)ba=co;
    }
  if(ba<N-s)ba=N-s;
  if(b>ba)a=c+1,b=ba;
  return s;
}
int main() {
  int T,i;
  for(scanf("%d",&T);T--;printf("%d %d\n",a,b)){
    scanf("%d",&N),D.clear(),D.resize(N);
    for(i=0;i<N-1;i++)scanf("%d%d",&a,&b),D[--a].push_back(--b),D[b].push_back(a);
    b=1<<30,d(0,-1);
  }
}