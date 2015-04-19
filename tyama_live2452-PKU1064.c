double a[10000];
int N,K;
int perform(double mi){
	int r=0,i=0;
	for(;i<N;i++)r+=(int)(a[i]/mi);
	return r>=K;
}
main2(){
	int i;
	scanf("%d%d",&N,&K);
	for(i=0;i<N;i++)scanf("%lf",a+i);
	double lo=0,hi=1000000;
	for(i=0;i<100;i++){
		double mi=(lo+hi)/2;
		if(perform(mi)){
			lo=mi;
		}else{
			hi=mi;
		}
	}
	printf("%.2f\n",floor(hi*100)/100);
}
int main(){int T;for(scanf("%d",&T);T--;printf(T>0?"\n":""))main2();return 0;}