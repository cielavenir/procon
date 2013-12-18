#define max(a,b) (a>b?a:b)
r,i;main(n){for(;i<5;i++)scanf("%d",&n),r+=max(n,40);printf("%d\n",r/5);}