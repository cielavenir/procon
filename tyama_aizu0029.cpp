#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
  string s,t;
  map<string,int>m;
  for(;cin>>s;)m[s]++;
  s=t=(*m.begin()).first;
  int M=(*m.begin()).second,l=s.length();
  for(map<string,int>::iterator it=m.begin();it!=m.end();it++){
    if(M<it->second)M=it->second,s=it->first;
    if(l<it->first.length())l=it->first.length(),t=it->first;
  }
  cout<<s<<' '<<t<<endl;
}