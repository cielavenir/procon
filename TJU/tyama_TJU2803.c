main(n){
	double a,b,c,d;
	for(scanf("%d",&n);n--;){
		scanf("%lf%lf%lf",&a,&b,&c);
		if(b*b<4*a*c){
			puts("No solution!");
		}else if(b*b-4*a*c<1e-8){
			printf("%.3f\n",-b/2/a);
		}else{
			d=sqrt(b*b-4*a*c);
			printf("%.3f %.3f\n",(-b-d)/2/a,(-b+d)/2/a);
		}
	}
}