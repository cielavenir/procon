#define m(a,b)(a<b?a:b)
r;main(c,a,n){for(gets(&c);r=~scanf("%d%d%d",&c,&a,&n);printf("%d\n",r+n+(c-n*2)/3))r=m(c,m(a,n)),c-=r,a-=r,n=m(c/2,a);}