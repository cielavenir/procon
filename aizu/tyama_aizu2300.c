double M,N,e,f,g,a[20][3],*x,*y;
n,i,j,v[20];
D(d,m,c){
	if(m==0){
		for(N=i=0;i<d-1;i++)for(j=i+1;j<d;j++)x=a[v[i]],y=a[v[j]],N+=(e=x[0]-y[0])*e+(f=x[1]-y[1])*f+(g=x[2]-y[2])*g;
		if(M<N)M=N;
	}else for(;c<=n-m;c++)v[d]=c,D(d+1,m-1,c+1);
}
main(m){
	scanf("%d%d",&n,&m);if(m<2)puts("0"),exit(0);
	for(i=0;i<n;i++)for(j=0;j<3;j++)scanf("%lf",a[i]+j);
	M=0;D(0,m,0);printf("%f\n",M),exit(0);
}