#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(){
  int total,i,u,a,p,n,m;
  for(;cin>>n,n;){
    map<int,int> school,senbatsu;
    vector< pair< pair<int,int>,int > > v;
    for(total=m=0;m<n;m++){
      cin>>i>>u>>a>>p;
      school[i]=u;
      v.push_back(make_pair(make_pair(-a,p),i));
    }
    sort(v.begin(),v.end());

    for(m=0;m<n;m++){
      if(
        (total<10&&senbatsu[school[v[m].second]]<3) ||
        (total<20&&senbatsu[school[v[m].second]]<2) ||
        (total<26&&senbatsu[school[v[m].second]]<1)
      ){
        senbatsu[school[v[m].second]]++;total++;
        cout<<v[m].second<<endl;
      }
    }
  }
}