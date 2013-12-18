int x[9999],d[9999],p[9999];
int lis(n){
	int i,j,I,J;
	for(i=0;i<n;d[i]=I+1,p[i]=J,i++)
		for(I=0,J=-1,j=i-1;~j;j--)
			if(x[j]<x[i]&&I<d[j])I=d[j],J=j;
	for(i=j=0;i<n;i++)
		if(d[i]>d[j])j=i;
	return j;
}
int lds(n){
	int i,j,I,J;
	for(i=0;i<n;d[i]=I+1,p[i]=J,i++)
		for(I=0,J=-1,j=i-1;~j;j--)
			if(x[j]>x[i]&&I<d[j])I=d[j],J=j;
	for(i=j=0;i<n;i++)
		if(d[i]>d[j])j=i;
	return j;
}
int backtrack(i){
	if(~p[i])backtrack(p[i]);
	printf(~p[i]?" %d":"%d",x[i]);
}
main(n,i){
	for(scanf("%d",&n),i=0;i<n;i++)scanf("%d",x+i);
	backtrack(lis(n));
	puts("");
	backtrack(lds(n));
	puts("");
}