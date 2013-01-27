#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
  string s;
  int i,j,n;
  while(true){
    cin >> s;
    if(s==".")return 0;
    cin >> n;
    for(i=0;i<s.length();i++){
      for(j=0;j<n;j++)cout << s;
      cout << endl;
      rotate(s.begin(),s.begin()+1,s.end());
    }
  }
}