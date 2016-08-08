#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main(){
  int n,i,p;
  string s;
  vector<pair<int,string> >v;
  for(;~scanf("%d",&n);){
    for(v.clear(),i=n;i--;){
      cin>>s>>p;
      v.push_back(make_pair(p,s));
    }
    sort(v.begin(),v.end());
    cout<<n<<endl;
    for(i=n;i;)
      cout<<v[--i].second<<endl;
    cout<<endl;
  }
}