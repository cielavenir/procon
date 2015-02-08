#include <algorithm>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

char table[]="AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
int fact[]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600};
int a[256];

struct P{
  bool operator()(const char i,const char j){
    int r=strchr(table,i)-strchr(table,j);
    return r<0;
  }
};

int main(){
  int i,j,n,f;
  char p[99],c;
  scanf("%d",&n);
  for(;n;n--){
    memset(a,0,sizeof(a));
    scanf("%s",p);
    for(i=0;i<strlen(p)-1;i++)
      for(j=i+1;j<strlen(p);j++)
        if(strchr(table,p[i])>strchr(table,p[j]))
          c=p[i],p[i]=p[j],p[j]=c;
    f=fact[strlen(p)];
    for(i=0;i<strlen(p);i++)
      a[p[i]]++;
    for(i='A';i<='Z';i++)f/=fact[a[i]];
    for(i='a';i<='z';i++)f/=fact[a[i]];

    string s=p;
    for(i=0;i<f;i++){
      puts(s.c_str());
      next_permutation(s.begin(),s.end(),P());
    }
  }
}