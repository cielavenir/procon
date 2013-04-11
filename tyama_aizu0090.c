float p=atan(1)*4/9,X[100],Y[100],x,y;main(n,i,j,k,a,b,c){for(;scanf("%d",&n),n;printf("%d\n",a)){
	for(i=0;i<n;i++)scanf("%f,%f",X+i,Y+i);
	for(a=i=0;i<n;a=a>b?a:b,i++)for(b=k=0;k<9;b=b>c?b:c,k++)for(x=X[i]+cos(p*k),y=Y[i]+sin(p*k),c=j=0;j<n;j++)if(hypot(X[j]-x,Y[j]-y)<1+1e-3)c++;
}exit(0);}