a[200];
int seq(n){
	int r=0;
	for(;n;n/=10){
		r+=(n%10)*(n%10);
	}
	return r;
}
int search(n){
	if(n==1)return 2;
	if(a[n])return a[n]==3?1:a[n];
	a[n]=3;
	return a[n]=search(seq(n));
}
main(){
	int i=2;
	for(a[1]=2;i<200;i++)if(!a[i])a[i]=search(i);
	for(;~scanf("%d",&i);printf("%d\n",a[i]-1))for(;i>199;)i=seq(i);
}