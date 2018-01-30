long long a,n;main(N){char s[1<<17],*p;for(scanf("%d%s",&N,s);N--;)for(p=s;*p;)a+=n=*p++%2?n+1:0;printf("%lld",a);}
