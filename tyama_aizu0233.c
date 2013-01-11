Z(n){if(n){int r;if(n%10<0)r=(n+1)%10+9,n-=10;else r=n%10;Z(n/-10);putchar(r+48);}}
main(n){for(;scanf("%d",&n),n;puts(""))Z(n);exit(0);}