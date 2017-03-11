main(n,r){for(;~scanf("%d",&n)&&n;printf("%d\n",r)){n=1000-n;for(r=0;n/500;r++)n-=500;for(;n/100;r++)n-=100;for(;n/50;r++)n-=50;for(;n/10;r++)n-=10;for(;n/5;r++)n-=5;for(;n;r++)n--;}exit(0);}
