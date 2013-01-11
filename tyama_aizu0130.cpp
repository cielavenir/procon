#include <iostream>
#include <deque>
using namespace std;

int main(){
  int n,c,i;
  for(cin>>n;n;n--){
    deque<char> d;
    string s;
    cin>>s;
    d.push_back(s[0]);
    for(i=1,c=0;i<s.size();i+=3){
      if(s[i]=='-')c++;
      else c--;
      if(c==d.size())d.push_back(s[i+2]);
      if(c==-1)d.push_front(s[i+2]),c=0;
    }
    for(i=0;i<d.size();i++)cout<<d[i];
    cout<<endl;
  }
}