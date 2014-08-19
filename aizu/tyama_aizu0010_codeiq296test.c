double x[3],y[3],a,b,c,A,B,C,X,Y,r;
main(n,i,j,k){
	i=0,j=1,k=2;
	for(scanf("%d",&n);n--;printf("%.3f %.3f %.3f\n",X,Y,r)){
		scanf("%lf%lf%lf%lf%lf%lf",x,y,x+1,y+1,x+2,y+2);
		a=2*x[j]-2*x[i],b=2*y[j]-2*y[i],c=x[i]*x[i]-x[j]*x[j]+y[i]*y[i]-y[j]*y[j];
		A=2*x[k]-2*x[i],B=2*y[k]-2*y[i],C=x[i]*x[i]-x[k]*x[k]+y[i]*y[i]-y[k]*y[k];
		X=(b*C-B*c)/(a*B-A*b),Y=(c*A-C*a)/(a*B-A*b);
		r=hypot(x[i]-X,y[i]-Y);
	}
exit(0);}