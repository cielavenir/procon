#include <iostream>
#include <map>
using namespace std;

int main(){
  int n;
  char x,y;
  for(;cin>>n&&n;cout<<endl){
    map<char,char>m;
    for(;n;n--){
      cin>>x>>y;
      m[x]=y;
    }
    for(cin>>n;n;n--){
      cin>>x;
      cout<<(m[x]?m[x]:x);
    }
  }
}
