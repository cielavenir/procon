#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main(){
  string s;
  int i;
  getline(cin,s);
  stringstream ss;
  vector<string>v;
  for(i=0;i<s.length();i++)
      if(s[i]==','||s[i]=='.')s[i]=' ';
  for(ss<<s;ss>>s;)if(2<s.length()&&s.length()<7)v.push_back(s);
  for(i=0;i<v.size();i++){
    if(i)cout<<' ';
    cout<<v[i];
  }
  cout<<endl;
}