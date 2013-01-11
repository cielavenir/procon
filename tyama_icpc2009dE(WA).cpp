#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int gcd2(int x,int y){return y?gcd2(y,x%y):x;} //x>y
int gcd(int x,int y){return x>y?gcd2(x,y):gcd2(y,x);}

int solve(vector<int> &a, vector<int> &b){ //a.size()<b.size()
  int f=1,r=0,i=0,j;
  while(i<a.size()){
    for(j=0;j<b.size();j++)
      if(gcd(a[i],b[j])>1){
        //printf("---%d %d\n",a[i],b[j]);
        r++;
        a.erase(a.begin()+i);
        b.erase(b.begin()+j);
        //i=0;
        goto next;
      }
    i++;
    next:;
  }
  return r;
}

int main(){
  int m,n,i,x;
  for(;scanf("%d%d",&m,&n),m|n;){
    vector<int> b,r,x,y;
    for(i=0;i<m;i++)scanf("%d",&x),b.push_back(x);
    for(i=0;i<n;i++)scanf("%d",&x),r.push_back(x);
    sort(b.begin(),b.end());
    sort(r.begin(),r.end());
    //sort(b.begin(),b.end(),greater<int>());
    //sort(r.begin(),r.end(),greater<int>());
x=b,y=r;
    printf("%d %d\n",solve(b,r),0); //returns 83 (instead of 85) for sample 7: greedy is dame!
  }
}