#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
using namespace std;

int main(){
  int n,x;
  map<int,int>m;
  for(;cin>>x;m[x]++);
  vector<pair<int,int> >v;
  for(map<int,int>::iterator it=m.begin();it!=m.end();it++)v.push_back(make_pair(it->second,it->first));
  sort(v.begin(),v.end(),greater<pair<int,int> >());
  vector<int>w;
  for(n=v[0].first,x=0;v[x].first==n;x++)w.push_back(v[x].second);
  sort(w.begin(),w.end());
  for(n=0;n<w.size();n++)cout<<w[n]<<endl;
}