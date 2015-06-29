main(){
  long long g,l,x,a,b,i;
  for(;~scanf("%I64d%I64d",&g,&l);){
    x=l/g;
    for(i=sqrt(x);;i--)if(!(x%i)){a=i;break;}
    printf("%I64d %I64d\n",g*a,g*x/a);
  }
}