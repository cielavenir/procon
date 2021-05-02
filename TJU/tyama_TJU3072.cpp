#include <vector>
#include <stack>
#include <cstdio>
using namespace std;

vector<int> a;
stack<int> s;

int pow2(int n){
  int r=1;
  for(;n;n--)r*=2;
  return r;
}

int getbit(int n,int b){
  for(;b;b--)n>>=1;
  return n&1;
}

void rail(int x){
  int n=0,k=x*2-1,i,c;
  for(n=pow2(k)-1;n/*>=0*/;n--){ //n is 1...2**(x*2-1)-1 bit=0..(x*2-1) push->0 pop->1
    for(c=0,i=k;~i;i--){
      if(getbit(n,i))c++;else c--;
      if(c>0)goto fail;
    }
    if(c){fail:continue;}
    for(i=k,c=1;~i;i--)
      if(getbit(n,i))
        a.push_back(s.top()),s.pop();
      else
        s.push(c++);
    for(i=0;i<a.size();i++)
      printf("%d",a[i]);
    a.clear();
    puts("");
  }
}

int main(){
  int n,x;
  scanf("%d",&n);
  for(;n;n--){
    scanf("%d",&x);
    rail(x);
  }
  return 0;
}