#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int a,b,n,f=0;
  string s;
  for(;cin>>n,n;){
    if(f)cout<<endl;
    vector<pair<int,string> >v;
    for(f=0;f<n;v.push_back(make_pair(a*3+b,s)),f++)
      cin>>s>>a>>b>>b;
    for(a=0;a<n;a++)
      for(b=0;b<n-1;b++)
        if(v[b].first<v[b+1].first)iter_swap(v.begin()+b,v.begin()+b+1);
    for(a=0;a<n;a++)
      cout<<v[a].second<<','<<v[a].first<<endl;
    f=1;
  }
}