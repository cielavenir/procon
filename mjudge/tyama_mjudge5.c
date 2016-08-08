a[16];main(n,i,b){for(;~scanf("%d",&n);puts("\n")){
memset(a,0,64);
printf("%d",n);
for(i=0;i<n;i++)scanf("%d",&b),a[b]++;
for(i=0;i<16;i++)
for(printf("\n%d : ",i);a[i]--;putchar('*'));
}return 0;}