main(i,n){
for(i=3,scanf("%d",&n);i*i<=n;++i)if(n%i==0){printf("%d\n",i-1);return 0;}
printf("%d\n",n%2==0&&n/2>2 ? n/2-1 : n>2 ? n-1 : 0);
}