#define cross(a1, b1, a2, b2) ((a1)*(b2)-(a2)*(b1))
main(){
	double a[100],b[100],s,t,x;
	int n,c=1,i;
	for(;scanf("%d",&n),n;printf("%d %.1lf\n",c,fabs(s-t)),c++){ // for(;~scanf("%d",&n);printf("%.1lf\n",fabs(s-t))) for CGL~3A
		for(i=0;i<n;i++)scanf("%lf%lf",a+i,b+i);
		for(i=s=t=0;i<n-1;i++){
			if((x=cross(a[i],b[i],a[i+1],b[i+1]))>0)s+=fabs(x)/2;
			else t+=fabs(x)/2;
		}
		if((x=cross(a[i],b[i],a[0],b[0]))>0)s+=fabs(x)/2;
		else t+=fabs(x)/2;
	}
exit(0);}