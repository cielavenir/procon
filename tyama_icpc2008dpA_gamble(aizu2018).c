int main(){
  int n,m,p,i,s,x[101];
  while(1){
    memset(x,0,sizeof(x));s=0;
    scanf("%d%d%d",&n,&m,&p);p=100-p;
    if(!n&&!m)return 0;
    for(i=1;i<=n;i++){
      scanf("%d",x+i);
      s+=x[i];
    }
    printf("%d\n",x[m]?p*s/x[m]:0);
  }
}