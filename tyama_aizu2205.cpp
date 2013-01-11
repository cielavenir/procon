#include <string>
#include <iostream>
#include <vector>
using namespace std;
#define S second
main(){
vector<pair<int,pair<string,int> > >v;
int i,j,n,m,k;
string s;
L:
if(v.clear(),cin>>n>>m,!n)return 0;
for(i=0;i<n;v.push_back(make_pair(k,make_pair(s,j))),i++)
  for(cin>>s>>k,j=0;s[j]=='*';j++);
for(k=0;m;m--)
  for(cin>>s,i=0;i<n;i++)
    if(s.substr(v[i].S.S)==v[i].S.first.substr(v[i].S.S))k+=v[i].first;
cout<<k<<endl;
goto L;
}