#include <vector>
#include <cstdio>
using namespace std;

int main(){
  int i=2,j;
  vector<int> v;
  vector<int>::iterator x,y;
  for(;i<37000;i++)v.push_back(i);
  for(x=v.begin();x<v.begin()+3000;x++)
    for(i=*x-1,y=x+i+1;*y+i<36998;y+=i)
      v.erase(y);
  while(scanf("%d",&i)&&i)printf("%d\n",v[i-1]);
}