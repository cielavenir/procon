//出力すべきは、(西岡先生の言う)n^3の和分に3を乗じたもの
main(a,n){scanf("%d",&a);a=0;while(scanf("%d",&n)>0){printf("%d %d %d\n",++a,n,n*(n+1)*(n+2)/6*(n+3)/4*3);}}