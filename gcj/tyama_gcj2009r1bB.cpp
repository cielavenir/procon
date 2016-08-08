#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
  string s,t;
  int m=0,n;
  for(cin>>n;m<n;){
    cin>>s;
    cout<<"Case #"<<++m<<": ";
    t=s="0"+s;
    while(strcmp(s.c_str(),t.c_str())<=0){
      next_permutation(s.begin(),s.end());
    }
    if(s[0]=='0')s=s.substr(1);
    cout<<s<<endl;
  }
}