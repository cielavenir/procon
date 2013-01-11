#include <stdio.h>
unsigned char *a;

void execute(char *p){
  char *x=p,c;
  int i=0,marker;
  while(c=*(x+i)){
    i++;
    switch(c){
      case '>': a++;break;
      case '<': a--;break;
      case '+': (*a)++;break;
      case '-': (*a)--;break;
      case '.': putchar(*a);break;
      case ',': *a=getchar();break;
      case '[': if(*a)execute(x+i);
                marker=1;
                while(marker){
                  if(*(x+i)=='[')marker++;
                  if(*(x+i)==']')marker--;
                  i++;
                }
                break;
      case ']': if(*a)i=0;else return;break;
      case 0: return;
    }
  }
}

int main(){
  int c,i=0,n,i1,i2,l=filelength(fileno(stdin))+1;
  unsigned char *da;
  char *p,*x;
  scanf("%d\n",&n);
  x=p=malloc(l);
  da=a=malloc(0x10000);

begin:
  i++;printf("PROGRAM #%d:\n",i);
  i1=i2=0;x=p;a=da;
  memset(p,0,l);
  memset(a,0,0x10000);

  while( (c=getchar())!=EOF ){
    switch(c){
      case '>':
      case '<':
      case '+':
      case '-':
      case '.':
      case ',': *(x++)=c;break;
      case '[': i1++;*(x++)=c;break;
      case ']': i2++;*(x++)=c;break;
      case '!':
      case '%': while( (c=getchar())!='\n' )if(c==EOF)break;break;
      case 'e': if(getchar()=='n'&&getchar()=='d')goto execute;
    }
  }
execute:
  //printf("%s\n",p);
  i1-i2 ? printf("COMPILE ERROR\n") : (execute(p),printf("\n"));
  if(i<n)goto begin;
  free(p);free(da);
  return 0;
}