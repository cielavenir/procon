//tyama_square.cpp
//‘Š“–‚È‚â‚Á‚Â‚¯ŽdŽ–w

#include <stdio.h>
#include <map>
using namespace std;

int main(){

while(1){
  map<int, int> point;
  map<int, int>::iterator p;
  int n[1501], m[1501];

  int count;
  int cn, cm, i, j;
  int x;

  n[0]=m[0]=count=0;

  scanf("%d %d", &cn, &cm);
  if(!cn){return 0;}

  for(i=0;i<cn;i++){
    scanf("%d", &x);
    n[i+1]=n[i]+x;
  }
  for(i=0;i<cm;i++){
    scanf("%d", &x);
    m[i+1]=m[i]+x;
  }
  
  for(i=0;i<=cn;i++){
    for(j=0;j<=cm;j++){
	  point[n[i]+m[j]]++;
	}
  }
  
  for(p=point.begin(); p!=point.end(); p++){
	count+=(p->second)*((p->second)-1)/2;
  }
  printf("%d\n",count);
}

}