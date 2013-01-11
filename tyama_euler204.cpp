#include <iostream>
#include <set>
#include <cstdio>
#define M 1000000001
using namespace std;

int main(){
  int z[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
  set<int> s;
  int x,j;
  s.insert(1);
  set<int>::iterator ite=s.begin();
  while(ite!=s.end()){
    x=*ite;
    for(j=0;j<sizeof(z)/sizeof(*z);j++)if(x<=M/z[j])s.insert(x*z[j]);
    ite++;
  }
  printf("%d\n",s.size());
}