int main(){
  int v[22],i=0,n,x,r;
  v[0]=0;v[1]=1;v[2]=2;
  for(i=3;i<22;i++)
    v[i]=v[i-1]+v[i-2];
  scanf("%d",&n);
  for(;n;n--){
    r=0;
    scanf("%d",&x);
    for(i=21;i;i--)
      if(x>=v[i])r+=v[i-1],x-=v[i];
    printf("%d\n",r);
  }
}