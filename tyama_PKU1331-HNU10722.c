int o(n,b){
  int r=0,p=1;
  while(n){
    if(n%10>=b)return -1;
    r+=n%10*p;n/=10;p*=b;
  }
  return r;
}

main(a,b,c,i,x,y,z){
  scanf("%d",&a);
  while(~scanf("%d%d%d",&a,&b,&c)){
    for(i=2;i<17;i++){
      x=o(a,i);y=o(b,i);z=o(c,i);
      if(x*y==z){printf("%d\n",i);break;}
    }
    if(i==17)printf("0\n");
  }
}