#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
  int i,n,m=0;
  string s;
  vector<string> v;
  while(cin >> n,n){
    v.clear();
    cout << "SET " << ++m << endl;
    for(i=0;i<n;i++){
      cin >> s;
      v.push_back(s);
    }
    for(i=0;i<n;i+=2)
      cout << v[i] << endl;
    i-=(n&1)?3:1;
    for(;i>=0;i-=2)
      cout << v[i] << endl;
  }
  return 0;
}