D(S,d,s,n){if(d==0)return S==s;int r=0;for(;n<10;n++)r+=D(S,d-1,s+n,n+1);return r;}
main(n,s){for(;scanf("%d%d",&n,&s),n|s;)printf("%d\n",D(s,n,0,0));exit(0);}