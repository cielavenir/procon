#define M 1000000
A[M+1]={1},i,z;main(y){for(z=10;z--;)for(i=0;i<=M-z-!z;i++)A[i+z+!z]=(A[i+z+!z]+A[i])%1000000009;long long m;for(;~scanf("%lld",&m);)--y&&printf("%d\n",A[m/111111]);exit(0);}