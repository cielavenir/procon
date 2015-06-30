#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int x[100][26];
int a[26];
int main(){
  string s;
  vector<string> v,w;
  int i=0,j,c;
  for(;;i++){
    cin >> s;
    if(s=="XXXXXX")break;
    for(j=s.length()-1;~j;j--){
      x[i][s[j]-'a']++;
    }
    v.push_back(s);
  }
  while(c!='\n')c=getchar();
  j=0;
  while(1){
    c=getchar();
    if(c=='X')return 0;
    if(c=='\n'){
      for(i=0;i<100;i++){
        if(!memcmp(x[i],a,102))
          w.push_back(v[i]);
      }
      if(!w.size())cout << "NOT A VALID WORD" << endl;
      else{
        sort(w.begin(),w.end());
        for(i=0;i<w.size();i++)
          cout << w[i] << endl;
        w.clear();
      }
      cout << "******" << endl;
      memset(a,0,102);
      j=0;
      continue;
    }
    a[c-'a']++;
  }
}