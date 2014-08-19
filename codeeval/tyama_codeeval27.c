D(n){if(n)D(n/2),putchar((n&1)+48);}
main(n){for(;~scanf("%d",&n);puts(""))D(n);}