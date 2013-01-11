#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(){
  int n,m,i,t,s,d;
  for(;cin>>n>>m,n;){
    vector<pair<int,pair<int,int> > >V;
    set<int> S;
    S.insert(1);
    for(i=0;i<m;i++){
      cin>>t>>s>>d;
      V.push_back(make_pair(t,make_pair(s,d)));
    }
    sort(V.begin(),V.end());
    for(i=0;i<m;i++)
      if(S.find(V[i].second.first)!=S.end())
        S.insert(V[i].second.second);
    cout<<S.size()<<endl;
  }
}