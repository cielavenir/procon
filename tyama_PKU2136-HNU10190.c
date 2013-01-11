#include <stdio.h>
int main(){
  int x[256],c,i,j,p,m=0;
  memset(x,0,sizeof(x));
  while((c=getc(stdin))!=EOF)x[c]++;
  for(i='A';i<='Z';i++)if(x[i]>m)m=x[i];
  for(j=m;j;j--)
    for(i='A';;i++){
      printf(x[i]>=j ? "*" : " ");
      for(p=i+1;p<='Z';p++)
        if(x[p]>=j)break;
      if(p=='Z'+1){puts("");break;}
      printf(" ");
    }
  puts("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z");
  return 0;
}