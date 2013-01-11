#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(){
  map<string,vector<int> >m;
  string s;int x,f;
  for(;cin>>s>>x;)
    m[s].push_back(x);
  map<string,vector<int> >::iterator it=m.begin();
  for(;it!=m.end();it++){
    cout<<it->first<<endl;
    vector<int>v=it->second;
    sort(v.begin(),v.end());
    for(f=0;f<v.size();f++){
      if(f)cout<<' ';
      cout<<v[f];
    }
    cout<<endl;
  }
}