//search all
#include <stdio.h>

int cows[20]={0};

int get(int n){
  int i=0,r=0;
  for(;n;i++){
    r+=(n&1)*cows[i];
    n>>=1;
  }
  return r;
}

int main(){
  int i=0,n,b,m=20000000;
  scanf("%d%d",&n,&b);
  for(;i<n;i++){
    scanf("%d",cows+i);
  }
  for(i=0;i<1048576;i++){
    n=get(i);
    if(n>=b&&n<m)m=n;
  }
  printf("%d\n",m-b);
  return 0;
}