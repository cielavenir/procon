#include <iostream>
#include <set>
#include <cstdio>
using namespace std;

int main(){
  char *table[10]={"th","st","nd","rd","th","th","th","th","th","th"};
  set<int> s;
  int x,i=0;
  s.insert(1);
  set<int>::iterator ite=s.begin();
  while(i<5842){
    x=*ite;
    if(x<1050000000)s.insert(x*2);
    if(x< 700000000)s.insert(x*3);
    if(x< 420000000)s.insert(x*5);
    if(x< 300000000)s.insert(x*7);
    i++;ite++;
  }
  while(true){
    ite=s.begin();
    scanf("%d",&x);
    if(!x)return 0;
    for(i=0;i<x-1;i++,ite++);
    printf("The %d%s humble number is %d.\n",x,x/10%10==1?"th":table[x%10],*ite);
  }
}