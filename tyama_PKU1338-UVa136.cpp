#include <iostream>
#include <set>
using namespace std;

int main(){
  set<int> s;
  int x,i=0;
  s.insert(1);
  set<int>::iterator ite=s.begin();
  while(i<1500){
    x=*ite;
    if(x*2>x)s.insert(x*2);
    if(x*3>x)s.insert(x*3);
    if(x*5>x)s.insert(x*5);
    i++;ite++;
  }

  while(true){
    ite=s.begin();
    scanf("%d",&x);
    if(!x)return 0;
    for(i=0;i<x-1;i++,ite++);
    printf("%d\n",*ite);
  }

  //ite--;printf("The 1500'th ugly number is %d.\n",*ite); //UVa136
}