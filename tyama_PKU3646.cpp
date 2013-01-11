#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  int _d,_k,i,x;
  while(cin>>_d>>_k,_d&&_k){
    vector<int> d,k;
    vector<int>::iterator id,ik;
    for(i=0;i<_d;i++){cin>>x;d.push_back(x);}
    for(i=0;i<_k;i++){cin>>x;k.push_back(x);}
    if(_d>_k)goto doom;
    sort(d.begin(),d.end());
    sort(k.begin(),k.end());
    id=d.begin(),ik=k.begin();
    for(x=0;ik!=k.end();ik++){
      if(*id<=*ik){
        x+=*ik;id++;
        if(id==d.end()){
          cout << x << endl;
          goto con;
        }
      }
    }
doom:
    cout << "Loowater is doomed!" << endl;
con:;
  }
  return 0;
}