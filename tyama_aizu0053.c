int pr[200000],p[100000];
main(i,j,k){
  for(k=1,i=2;i<200000;i++)
    if(!pr[i])
      for(p[k++]=i,j=i*2;j<200000;j+=i)pr[j]=1;
  for(k=1;k<10001;k++)
    p[k]+=p[k-1];
  for(;scanf("%d",&i),i;printf("%d\n",p[i]));
  return 0;
}