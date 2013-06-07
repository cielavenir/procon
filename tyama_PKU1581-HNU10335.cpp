#include <string>
#include <iostream>
using namespace std;

int main(){
  string wn,n;
  int ws=0,s,wp=1e9,p,k,i,a[4],b[4];
  cin>>k;
  for(;k;k--){
    s=p=0;
    cin>>n>>a[0]>>b[0]>>a[1]>>b[1]>>a[2]>>b[2]>>a[3]>>b[3];
    for(i=3;~i;i--)
      if(b[i])s++,p+=b[i]+20*(a[i]-1);
    if(ws<s||(ws==s&&wp>p))wn=n,ws=s,wp=p;
  }
  cout<<wn<<" "<<ws<<" "<<wp<<endl;
  return 0;
}