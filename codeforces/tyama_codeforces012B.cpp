#include <string>
#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
int main(){
  int i=0;
  string s,t;
  cin>>s>>t;
  sort(s.begin(),s.end());
  for(;i<s.length();i++)
    if(s[i]!='0'){swap(s[0],s[i]);break;}
  puts(s==t?"OK":"WRONG_ANSWER");
}