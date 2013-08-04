#import <iostream>
#import <vector>
#import <cstring>
using namespace std;

int x[10001];

void tree(){
  int n,i=0,a,b;
  memset(x,0,sizeof(x));

  cin >> n;
  for(;i<n-1;i++){
    cin >> a >> b;
    x[b]=a;
  }
  cin >> a >> b;

  vector<int> va,vb;
  while(x[a]){
    va.push_back(a);
    a=x[a];
  }
  va.push_back(a); //It is possible that the common ancestor is root.
  while(x[b]){
    vb.push_back(b);
    b=x[b];
  }
  vb.push_back(b);

  int k=1;
  while(va[va.size()-k]==vb[vb.size()-k])k++;
  cout << va[va.size()-k+1] << endl; //hence va must include root.
}

int main(){
  int n,i=0;
  cin >> n;
  for(;i<n;i++)tree();
  return 0;
}