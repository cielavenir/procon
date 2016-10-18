#include <string>
#include <iostream>
#include <vector>
using namespace std;

main(){
  vector<pair<int,pair<string,int> > >v;
  int i=0,j,n,m,k;
  string s;
  for(cin>>n>>m;i<n;i++){
    cin>>s>>k;
    for(j=0;s[j]=='*';j++);
    v.push_back(make_pair(k,make_pair(s,j)));
  }
  for(k=0;m;m--){
    cin>>s;
    for(i=0;i<n;i++)
      if(s.substr(v[i].second.second)==v[i].second.first.substr(v[i].second.second))k+=v[i].first;
  }
  cout<<k<<endl;
}