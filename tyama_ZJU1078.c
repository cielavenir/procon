int pal(int _n,int b){
  int r=0,n=_n;
  while(n){
    r=r*b+n%b;
    n/=b;
  }
  if(r!=_n)return 0;
  return 1<<b;
}

int main(){
  int n,i,c;
  while(scanf("%d",&n),n){
    c=0;
    for(i=2;i<17;i++)c+=pal(n,i);
    if(c==0){printf("Number %d is not a palindrom\n",n);continue;}
    printf("Number %d is palindrom in basis",n);
    for(i=2;i<17;i++)
      if(c&(1<<i))printf(" %d",i);
    puts("");
  }
  return 0;
}