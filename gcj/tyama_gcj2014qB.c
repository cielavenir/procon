main(){
	int T,I=0;
	long double c,f,x;
	long double ret,sum,cps,rettmp;
	for(scanf("%d",&T);I<T;I++){
		printf("Case #%d: ",I+1);
		scanf("%Lf%Lf%Lf",&c,&f,&x);
		sum=0;
		cps=2;
		ret=sum+x/cps;
		for(;sum<ret;){
			sum+=c/cps;
			cps+=f;
			rettmp=sum+x/cps;
			if(ret>rettmp)ret=rettmp;
		}
		printf("%.9Lf\n",ret);
	}
}