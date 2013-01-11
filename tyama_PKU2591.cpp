#include <cstdio>
#include <queue>
#define M 1031926803

using namespace std;
int s[10000000];

int main(){
  int i=0;
  queue<int>a,b;
  a.push(1),b.push(1);
  for(;i<10000000;i++){
    int ax=a.front(),bx=b.front();
    if(!a.empty()&&ax<bx){
      s[i]=ax;
      a.pop();
      if(ax<M/2)a.push(ax*2+1);
      if(ax<M/3)b.push(ax*3+1);
    }else{
      if(ax==bx)a.pop();
      s[i]=bx;
      b.pop();
      if(bx<M/2)a.push(bx*2+1);
      if(bx<M/3)b.push(bx*3+1);
    }
  }
  for(;~scanf("%d",&i);printf("%d\n",s[i-1]));
  return 0;
}