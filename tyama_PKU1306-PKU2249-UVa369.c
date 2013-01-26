c(a,b){
  long long r,i;
  for(r=i=1,a++;i<=b;i++)r*=a-i,r/=i;
  return (int)r;
}

main(a,b){while(scanf("%d%d",&a,&b),a)printf("%d things taken %d at a time is %d exactly.\n",a,b,a<b*2?c(a,a-b):c(a,b));}