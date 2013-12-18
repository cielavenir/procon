#include <map>
#include <cstdio>
#define between(a,x,b) ((a)<=(x)&&(x)<=(b))
using namespace std;

int main(){
  map<int,int> m;
  map<int,int>::iterator ite;
  int n,c,i,x;
  char s[100];

  scanf("%d",&n);
  for(;n;n--){
    scanf("%s",s);
    for(i=c=x=0;c<7;i++){
      if(s[i]=='-')continue;
      if(between('A',s[i],'Z')){
        if(s[i]>='R')s[i]--;
        x=x*10+(s[i]-'A')/3+2;
      }else
        x=x*10+s[i]-'0';
      c++;
    }
    m[x]++;
  }
  for(c=0,ite=m.begin();ite!=m.end();ite++)
    if(ite->second>1)printf("%03d-%04d %d\n",ite->first/10000,ite->first%10000,ite->second),c++;
  if(c==0)puts("No duplicates.");
  return 0;
}
//live5420
//int main(){int i=0,n;for(scanf("%d",&n);i<n;main2())if(i++)puts("");}