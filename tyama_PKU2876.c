fra(n,i){if(!n){putchar('-');return 1;}i=fra(n-1);for(;i;i--)putchar(' ');return 3*fra(n-1);}
main(a,n){for(;~scanf("%d",&n);printf(--a?"\n":""),fra(n,a));}