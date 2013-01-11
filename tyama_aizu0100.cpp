#include <cstdio>
#include <map>
#include <vector>
using namespace std;

int main(){
  int n,i,p,q,f;
  for(;scanf("%d",&n),n;){
    map<int,long long>m;
    vector<int>v;
    for(;n--;){
      scanf("%d%d%d",&i,&p,&q);
      if(m.find(i)==m.end())v.push_back(i);
      m[i]+=(long long)p*q;
    }
    for(f=i=0;i<v.size();i++){
      if(m[v[i]]>=1000000)printf("%d\n",v[i]),f=1;
    }
    if(!f)puts("NA");
  }
}