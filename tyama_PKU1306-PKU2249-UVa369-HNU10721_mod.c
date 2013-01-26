//Overflow unless long long...
//Uncomment-out for PKU1306/UVA369/HNU10721.
//You have to use %I64d for HNU (maybe due to msvcrt).

main(n,k,j){
  long long i;
  for(;scanf("%d%d",&n,&k),n;){
    i=1;
    /*printf("%d things taken %d at a time is ",n,k);*/
    if(k>n/2)k=n-k;
    for(j=1;j<=k;)i=i*n--/j++;
    printf("%lld\n"/*"%lld exactly.\n"*/,i);
  }
  /*return 0;*/
}