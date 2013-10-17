#include <algorithm>
#include <iostream>
#define between(a,x,b) ((a)<=(x)&&(x)<=(b))
using namespace std;

int main(){
  int i=0;
  string s;
  cin >> s;
  if(between('A',s[0],'Z')||s[0]=='_')
    {cout << "Error!" << endl;return 0;}
  if(find(s.begin(),s.end(),'_')!=s.end()){
    for(;i<s.length();i++)
      if(between('A',s[i],'Z'))
        {cout << "Error!" << endl;return 0;}
    for(i=0;i<s.length();i++)
      if(s[i]=='_'){
        if(s[i+1]=='_'||s[i+1]==0){cout << "Error!" << endl;return 0;}
        s.erase(i,1),s[i]-=0x20;
      }
    cout << s << endl;
  }else{
    for(i=0;i<s.length();i++)
      if(between('A',s[i],'Z'))s.insert(i,1,'_'),s[++i]+=0x20;
    cout << s << endl;
  }
}