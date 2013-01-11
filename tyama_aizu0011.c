a[31];
main(w,n,x,y,z){
for(w=1;w<31;w++)a[w]=w;
scanf("%d%d",&w,&n);
for(;n--;z=a[x],a[x]=a[y],a[y]=z)scanf("%d,%d",&x,&y);
for(n=1;n<=w;n++)printf("%d\n",a[n]);
exit(0);}