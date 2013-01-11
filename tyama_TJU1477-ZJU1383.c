int main(m,n,i,c){
  scanf("%d",&m);
  for(;m;m--){
    scanf("%d",&n);
    i=c=0;
    while(n){
      if(n&1){printf(c?" %d":"%d",i);c++;}
      n/=2;i++;
    }
    puts("");
  }
}