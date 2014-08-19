a[10]={63,6,91,79,102,109,125,39,127,111};
main(n,c,d,x,i){for(;scanf("%d",&n),~n;)for(c=0;n--;puts(""),c=a[x])for(scanf("%d",&x),c^=a[x],i=6;~i;i--)putchar(48+((c>>i)&1));exit(0);}