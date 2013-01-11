#include <cstdio>
#include <algorithm>

int p[4],q[4];

void hitandblow(){
  int h=0,b=0,x,i=0,j;
  for(;i<4;i++)
    if(p[i]==q[i])h++;
  for(i=0;i<24;i++){
    std::next_permutation(p,p+4);
    x=j=0;
    for(j=0;j<4;j++)
      if(p[j]==q[j])x++;
    if(b<x)b=x;
  }
  printf("%dA%dB\n",h,b-h);
}

int main(){
  int n,f,i,c;
  scanf("%d",&n);getchar(); //kill linebreak
  for(;n;n--){
    f=i=0;
    while((c=getchar())!='\n'){
      if(c==' '){f=1;i=0;continue;}
      (f?q:p)[i++]=c;
    }
    hitandblow();
  }
  return 0;
}