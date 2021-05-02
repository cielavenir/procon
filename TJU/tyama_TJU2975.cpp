#include <cstdio>
#include <string>
#define between(a,x,b) ((a)<=(x)&&(x)<=(b))
using namespace std;

int main(){
  string s="";
  char c;
  int x[26]={0},m=0,i=0,k;
  while((c=getchar())!=EOF){
    s+=c;
    if(between('a',c,'z'))x[c-'a']++;
    if(between('A',c,'Z'))x[c-'A']++;
  }
  for(;i<26;i++)
    if(x[i]>m)
      m=x[i],k=i;
  k=26-(k+26-8)%26;

  for(i=0;i<s.length();i++){
    if(between('a',s[i],'z'))printf("%c",'a'+(s[i]-'a'+k)%26);
    else if(between('A',s[i],'Z'))printf("%c",'A'+(s[i]-'A'+k)%26);
    else printf("%c",s[i]);
  }
  return 0;
}