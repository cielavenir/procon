#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 101198
int prime[MAX];
int p[11000];

int main(){
  int i,j,k,l,m;
  prime[0]=-1;prime[1]=-1;
  for(k=0,i=2;i<MAX;i++)
    if(!prime[i])
      for(prime[i]=k,p[k++]=i,j=i*2;j<MAX;j+=i)
        prime[j]=-1;
  for(;scanf("%d%d",&l,&m),~l;){
    vector<int> v;
    for(l++;prime[l]<0;l++);
    for(i=prime[l];i<prime[l]+m;i++)
      for(j=i;j<prime[l]+m;j++)
        v.push_back(p[i]+p[j]);
    sort(v.begin(),v.end());
    printf("%d\n",v[m-1]);
  }
}