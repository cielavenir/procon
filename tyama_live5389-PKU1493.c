#include <stdio.h>
main(){
  int x[12],o,n,m=0,i;
  char s[27];
  for(;scanf("%d",&n),n;m=0){
    getchar();
    memset(x,0,sizeof(x));
    for(o=0;o<n;o++){
      fgets(s,27,stdin);
      s[25]=0;
      for(i=0;i<25;i++)
        if(s[i]=='X')x[o]++;
      if(m<x[o])m=x[o];
    }
    for(i=o=0;o<n;o++)
      i+=m-x[o];
    printf("%d\n",i);
  }
}