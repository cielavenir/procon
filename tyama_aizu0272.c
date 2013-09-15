#define x(a)for(i=0;i<n;i++)scanf("%d",a+i);qsort(a,n,4,y)
a[40000],b[40000];int y(int *a,int *b){return *b-*a;}
main(n,i){for(;scanf("%d",&n),n;){x(a);x(b);for(i=0;i<n/2;i++)if(a[i*2]>b[i]){printf("%d\n",i*2+1);break;}if(i==n/2)puts("NA");}exit(0);}