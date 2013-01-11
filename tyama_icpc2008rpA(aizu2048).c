z[999],p[168];
int s(n){
  int i=0,s=0;
  for(;i<168;i++){
    if(!(n%p[i])){
      for(;!(n%p[i]);n/=p[i]);
      if(n==1)return p[i]-s;
      s+=p[i];
    }
  }
  return n-s;
}
main(i,j){
  for(z[0]=z[1]=1;i<999;i++)
    if(!z[i])
      for(j=2*i;j<999;j+=i)
        z[j]=1;
  for(i=j=0;j<999;j++)
    if(!z[j])
      p[i++]=j;
  for(;scanf("%d%d",&i,&j),i;)
    printf("%c\n",'a'+(s(i)<s(j)));
  return 0;
}