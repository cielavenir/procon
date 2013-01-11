main(a,b,m,i,M){
  for(;;){
    M=0;
    for(i=0;i<5;i++){
      scanf("%d%d",&a,&b);
      if(a+b==0)return 0;
      if(a+b>M)M=a+b,m=i;
    }
    printf("%c %d\n",m+65,M);
  }
}