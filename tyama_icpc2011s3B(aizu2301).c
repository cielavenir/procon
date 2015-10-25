K;double P,E,T;
double dfs(int K,double L,double R){
	double H=(L+R)/2;
	if(!K)return fabs(T-H)<E;
	if(R<T-E||T+E<L)return 0;
	if(T-E<=L&&R<=T+E)return 1;
	double a=dfs(K-1,L,H),b=dfs(K-1,H,R);
	return H<=T ? P*a+(1-P)*b : P*b+(1-P)*a;
}
main(){
	double L,R;
	scanf("%d%lf%lf%lf%lf%lf",&K,&L,&R,&P,&E,&T);
	K=!printf("%f\n",dfs(K,L,R));
}