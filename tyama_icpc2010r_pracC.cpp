#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
/* 1 */ main(){string s;for(;cin>>s,cin>>s;printf("o%s\n",count(s.begin(),s.end(),'B')%2?"n":"ff"));}
/* 2 */ //string s;main(){cin>>s,cin>>s?printf("o%s\n",count(s.begin(),s.end(),'B')%2?"n":"ff"),main():0;}
/* 3 */ //char s[99];main(i,n,x){for(;scanf("%d",&n),n;printf("o%s\n",x%2?"n":"ff"))for(i=x=0,scanf("%s",s);i<strlen(s);i++)if(s[i]=='B')x++;}