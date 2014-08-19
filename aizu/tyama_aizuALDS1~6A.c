a[2000000],i;int z(int *a,int *b){return *a-*b;}
main(n){
for(scanf("%d",&n);i<n;i++)scanf("%d",a+i);
qsort(a,n,4,z);
for(i=0;i<n;i++)printf(i<n-1?"%d ":"%d\n",a[i]);
exit(0);}