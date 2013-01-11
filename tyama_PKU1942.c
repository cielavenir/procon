main(){
  unsigned n,m,i,j;
  long long r;
  for(;scanf("%u%u",&n,&m),n|m;){
    n+=m;
    if(m>n-m)m=n-m;
    /*nCm*/
    for(r=1,i=n,j=1;i>n-m;i--){
      r*=i;
      if(!(r%j))r/=j,j++;
    }
    for(;j<=m;r/=j,j++);
    printf("%I64d\n",r);
  }
}