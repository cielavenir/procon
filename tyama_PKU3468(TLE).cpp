#include <iostream>
using namespace std;
int main(){
  int i1,i2,i3,n,q,i=0;
  char c;
  long long *a,s;
  cin >> n >> q;
  a=new long long[n+1];
  for(i1=1;i1<=n;i1++)cin >> a[i1];
  for(;i<q;i++){
    cin >> c;
    if(c=='Q'){
      cin >> i1 >> i2; s=0;
      for(;i1<=i2;i1++)s+=a[i1];
      cout << s << endl;
    }else{
      cin >> i1 >> i2 >> i3;
      for(;i1<=i2;i1++)a[i1]+=i3;
    }
  }
  return 0;
}