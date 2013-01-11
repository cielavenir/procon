//adapted from icpc1998dA
#define cross(a1, b1, a2, b2) ((a1)*(b2)-(a2)*(b1))
int main(){
	double a[20],b[20],s,t,x;
	int n=0,c=1,i;
	for(;~scanf("%lf,%lf",a+n,b+n);n++);
	for(i=s=t=0;i<n-1;i++){
		if((x=cross(a[i],b[i],a[i+1],b[i+1]))>0)s+=fabs(x)/2.0;
		else t+=fabs(x)/2;
	}
	if((x=cross(a[i],b[i],a[0],b[0]))>0)s+=fabs(x)/2;
	else t+=fabs(x)/2;
	printf("%.6f\n",fabs(s-t));
exit(0);}