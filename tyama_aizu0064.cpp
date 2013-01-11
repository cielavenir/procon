#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(){
  string s;
  int i,x,r=0;
  for(;cin>>s;){
    stringstream ss;
    for(i=0;i<s.length();i++)
      if(!isdigit(s[i]))s[i]=' ';
    for(ss<<s;ss>>x;r+=x);
  }
  cout<<r<<endl;
}