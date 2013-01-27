#include <stdio.h>
#include <string.h>

char code[500];
char dec[500];
char t[28]=" ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int x,y;
int f,s;

void decode(){
  int xi=0,xa=x,yi=0,ya=y,i=0,j=0,c=0;
  while(c<x*y-1){
    for(;i<xa-1;i++)
      dec[c++]=code[x*j+i];
    for(;j<ya-1;j++)
      dec[c++]=code[x*j+i];
    if(c>=x*y-1)break;
    for(;i>xi;i--)
      dec[c++]=code[x*j+i];
    for(;j>yi+1;j--)
      dec[c++]=code[x*j+i];
    xi++;yi++;xa--;ya--;
  }
  dec[c]=code[x*j+i];
}

void print(char *p){
  int i=0,x=((p[0]-'0')<<4)+((p[1]-'0')<<3)+((p[2]-'0')<<2)+((p[3]-'0')<<1)+(p[4]-'0');
  if(x>26)return;
  if(x==0){
    if(f)s++;
    return;
  } 
  f=1;
  for(;i<s;i++)printf(" ");
  s=0;
  printf("%c",t[x]);
}

int main(){
  int i,n,j;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    printf("%d ",i);
    scanf("%d%d%s",&y,&x,code); /*ghaa!*/
    memset(dec,0,sizeof(dec));
    f=0;s=0;

    decode();
    for(j=0;j+5<=x*y;j+=5)print(dec+j);
    puts("");
  }
  return 0;
}