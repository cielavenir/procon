#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
int table[300000];

int main(){
  int i,j,n,x;
  for(i=7;i<=300000;i+=7){
    table[i-1]=table[i+1]=1;
  }
  for(i=7;i<=(int)::sqrt(300000);i+=7){
    if(table[x=i-1])
      for(j=x<<1;j<=300000;j+=x)table[j]=0;
    if(table[x=i+1])
      for(j=x<<1;j<=300000;j+=x)table[j]=0;
  }

  while(1){
    vector<int> v;
    scanf("%d",&n);
    if(n==1)return 0;
    printf("%d:",n);

/*
    for(i=7;i<=n+1;i+=7){
      if(table[x=i-1] && !(n%x))printf(" %d",x);
      if(table[x=i+1] && !(n%x))printf(" %d",x);
    }
*/

    for(i=7;i<(j=(int)::sqrt(n));i+=7){
      if(!(n%(x=i-1))){
        if(table[x])v.push_back(x);
        if(table[n/x]&&n!=x*x)v.push_back(n/x);
      }
      if(!(n%(x=i+1))){
        if(table[x])v.push_back(x);
        if(table[n/x]&&n!=x*x)v.push_back(n/x);
      }
    }
    if(i-j==1&&!(n%(x=i-1))){
      if(table[x])v.push_back(x);
      if(table[n/x]&&n!=x*x)v.push_back(n/x);
    }
    if(table[n])v.push_back(n);
    sort(v.begin(),v.end());
    for(i=0;i<v.size();i++)printf(" %d",v[i]);

    puts("");
  }
}