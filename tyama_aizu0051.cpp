#include <iostream>
#include <algorithm>
#include <functional>
#include <cmath>
using namespace std;

int main(){
  string s,t;
  for(cin>>s;cin>>s;cout<<atoi(s.c_str())-atoi(t.c_str())<<endl)
    t=s,sort(t.begin(),t.end()),sort(s.begin(),s.end(),greater<int>());
}