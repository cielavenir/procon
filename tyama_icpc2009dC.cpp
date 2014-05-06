/*1734-1830*/
/*TLE in Online Judge. Should be optimized more.*/
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

char s[12][9],x[12][9];
int fact[11];

int main(){
  int n,r,i,j,k,p,z,l;
  for(i=0;i<11;i++)fact[i]=1;
  for(i=2;i<11;i++)
    for(j=2;j<=i;j++)fact[i]*=j;

  for(;scanf("%d",&n),n;printf("%d\n",r/fact[10-p])){
    int t[10]={'0','1','2','3','4','5','6','7','8','9'};
    for(r=i=0;i<n;i++)
      scanf("%s",s+i);
    set<char> se;
    for(i=0;i<n;i++)
      for(j=0;j<strlen(s[i]);j++)
        se.insert(s[i][j]);
    p=se.size();

    set<char>::iterator it=se.begin();
    map<char,int> m;
    for(i=0;i<p;i++){
      m[*it]=i;
      it++;
    }
    for(;i<10;i++)
      m[i]=i;
    for(k=0;k<3628800;k++){ //dorokusai! Can be Perm(10,se.size())
      memcpy(x,s,sizeof(x));
      for(i=0;i<n;i++){
        l=strlen(s[i]);
        for(j=0;j<l;j++){
          x[i][j]=t[m[x[i][j]]];
          if(!j&&x[i][j]=='0'&&l>1)goto next;
        }
      }
      z=0;
      for(i=0;i<n-1;i++){
        z+=strtol(x[i],NULL,10);
      }
      if(z==strtol(x[n-1],NULL,10))r++;
      next:;
      next_permutation(t,t+10);
    }
  }
}