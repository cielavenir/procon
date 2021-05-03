a[100000],v[1000001],i,j=-1,r,n;main(){
	for(scanf("%d",&n);i<n;i++)scanf("%d",a+i);
	for(i=0;i<n;r=r>i-j?r:i-j,v[a[i++]]++)for(;v[a[i]];)v[a[++j]]--;
	i=!printf("%d",r);
}