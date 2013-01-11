#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

int gcd(int x,int y){return y?gcd(y,x%y):x;}

void pi(int n){
  int i,j,s=0,t=0;
  vector<int>v;
  for(i=0;i<n;i++){
    cin >> j;
    v.push_back(j);
  }
  for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++){
      s++;
      if(gcd(v[j],v[i])==1)t++;
    }
  if(!t){puts("No estimate for this data set.");return;}
  printf("%f\n",sqrt(s*6.0/t));
}

int main(){int n;while(cin>>n,n)pi(n);return 0;}