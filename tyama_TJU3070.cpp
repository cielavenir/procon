#include <string>
#include <iostream>
using namespace std;

int main(){
  string s;
  int n,k,i;
  for(cin >> n;n;n--){
    cin >> s >> k;
    for(i=0;i<s.length();i++)s[i]='a'+(s[i]-'a'+k)%26;
    cout << s << endl;
  }
  return 0;
}