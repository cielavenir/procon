#include <algorithm>
#include <iostream>
#define between(a,x,b) ((a)<=(x)&&(x)<=(b))
using namespace std;

int main(){
  int i=0;
  string s,t,u="_";
  cin >> s;t=s;
  int start_underscore=0;
  int end_underscore=0;
  for(;s[0]=='_';s.erase(0,1))start_underscore++;
  if(s[0]==0){cout<<string(start_underscore,'_')<<endl;return 0;}
  for(;s[s.length()-1]=='_';s.erase(s.length()-1,1))end_underscore++;
  if(between('A',s[0],'Z')||between('0',s[0],'9'))
    {cout<<string(start_underscore,'_')<<s<<string(end_underscore,'_')<<endl;return 0;}
  t=s;
 
  if(find(s.begin(),s.end(),'_')!=s.end()){ //underscore
    for(;i<s.length();i++)
      if(between('A',s[i],'Z'))
        {cout<<string(start_underscore,'_')<<t<<string(end_underscore,'_')<<endl;return 0;}
    for(i=0;i<s.length();i++)
      if(s[i]=='_'){
        if(s[i+1]=='_'||s[i+1]==0||between('0',s[i+1],'9')){cout<<string(start_underscore,'_')<<t<<string(end_underscore,'_')<<endl;return 0;}
        s.erase(i,1),s[i]-=0x20;
      }
    cout<<string(start_underscore,'_')<<s<<string(end_underscore,'_')<<endl;
  }else{ //camelcase
    for(i=0;i<s.length();i++)
      if(between('A',s[i],'Z')){
		  s.insert(i,1,'_'),s[++i]+=0x20;
      }
    cout<<string(start_underscore,'_')<<s<<string(end_underscore,'_')<<endl;
  }
}