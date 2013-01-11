#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int n,x,i,j;
  cin >> n;
  for(;n;n--){
    vector<int> v;
    cin >> x;i=x--;
    for(;i;i--){
      v.push_back(i);
      for(j=i;j;j--)
        rotate(v.begin(),v.begin()+1,v.end());
    }
    for(i=x;i>=0;i--){
      cout << v[i];
      if(i>0)cout << " ";
    }
    cout << endl;
  }
  return 0;
}