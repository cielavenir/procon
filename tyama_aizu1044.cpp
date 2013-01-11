//PKU3157
#include <algorithm>
#include <iostream>
#define between(a,x,b) ((a)<=(x)&&(x)<=(b))
using namespace std;

int main(){
  int i=0;
  string s,t;
  for(;cin >> s >> t,t!="X";){
  if(find(s.begin(),s.end(),'_')!=s.end()){
    if(t!="D"){
      for(i=0;i<s.length();i++)
        if(s[i]=='_'){
          if(s[i+1]=='_'||s[i+1]==0){cout << "Error!" << endl;return 0;}
          s.erase(i,1),s[i]-=0x20;
        }
      if(t=="U")s[0]-=0x20;
    }
    cout << s << endl;
  }else{
    if(between('A',s[0],'Z'))s[0]+=0x20;
    if(t=="U")s[0]-=0x20;
    if(t=="D")
      for(i=0;i<s.length();i++)
        if(between('A',s[i],'Z'))s.insert(i,1,'_'),s[++i]+=0x20;
    cout << s << endl;
  }
  }
}