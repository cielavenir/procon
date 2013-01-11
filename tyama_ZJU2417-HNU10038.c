int main(n,i){
  while(1){
    i=1;
    scanf("%d",&n);
    if(!n)return 0;
    while(!(n&1)){i<<=1;n>>=1;}
    printf("%d\n",i);
  }
}