p(a,b,m,r){if(!b)return 1;if(!a)return 0;for(r=0;m;m--)r+=p(a-1,b-m,m);return r;}
main(n,a,b){scanf("%d",&n);for(;n;n--)scanf("%d%d",&b,&a),printf("%d\n",p(a,b,b,n));}