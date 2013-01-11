int main(){
  char p[33],*q;
  int n,x;
  while(1){
    scanf("%s",p);
    if(*p=='0')return 0;
    n=0;x=0;q=p;
    while(*q){
     n+=n+*q-'0';
     x+=*q-'0';
     q++;
    }
    printf("%d\n",n*2-x);
  }
}