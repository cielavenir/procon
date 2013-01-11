/*2602‚Ì—Þ‘è*/
#include <stdio.h>
int x[9];
main(a,b,n,i,c){
  while(c!='\n')c=getchar();
  for(i=1;(c=getchar())!=EOF;){
    if(c=='\n'){
      n=i--;
      for(;i>1;i--){
        if(x[i]>4)x[i-1]++;
        x[i]=0;
      }
      if(x[i]>9)putchar('1'),x[i]-=10;
      for(i=1;i<n;i++)
        putchar(x[i]+'0');
      puts("");
      i=1;continue;
    }
    x[i++]=c-'0';
  }
}