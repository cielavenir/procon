i,j,a[3],t;main(T){for(scanf("%d",&T);t<T;puts("")){
scanf("%02d:%02d:%02d",a,a+1,a+2);
printf("%d ",++t);
for(j=5;~j;j--)for(i=0;i<3;i++)printf("%d",(a[i]>>j)&1);
printf(" ");
for(i=0;i<3;i++)for(j=5;~j;j--)printf("%d",(a[i]>>j)&1);
}}