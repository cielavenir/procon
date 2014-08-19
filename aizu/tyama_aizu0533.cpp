#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int x,i;
  vector<int>w,k;
  for(i=0;i<10;i++)scanf("%d",&x),w.push_back(x);
  for(i=0;i<10;i++)scanf("%d",&x),k.push_back(x);
  sort(w.begin(),w.end());
  sort(k.begin(),k.end());
  printf("%d %d\n",w[7]+w[8]+w[9],k[7]+k[8]+k[9]);
}