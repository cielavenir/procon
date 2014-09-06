int main(){
	double d;
	for(;~scanf("%lf",&d);){
		int n=d*3600;
		printf("%d.%02d'%02d\"\n",n/3600,n/60%60,n%60);
	}
	return 0;
}