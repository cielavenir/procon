#include <stdio.h>

int main(int argc,char **argv){
  if(argc>1)freopen(argv[1],"rb",stdin);
  int a,b,n,i,array[3000];
loop:
  if(scanf("%d",&n)==EOF)return 0;
  for(i=1;i<n;i++)array[i]=0;
  scanf("%d",&a);
  for(i=1;i<n;i++){
    scanf("%d",&b);
    array[abs(a-b)]=1;
    a=b;
  }
  for(i=1;i<n;i++)if(!array[i]){puts("Not jolly");goto loop;}
  puts("Jolly");goto loop;
}