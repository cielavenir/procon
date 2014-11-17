#include <vector>
#include <cstdio>
int main(){
	int n;
	long long k;
	double mi=0,ma=0;
	scanf("%d",&n);
	std::vector<double>v(n);
	for(int i=0;i<n;i++){
		scanf("%lf",&v[i]);
		if(ma<v[i])ma=v[i];
	}
	scanf("%lld",&k);
	//for(;mi+1e-9<ma;){
	for(int x=0;x<50;x++){
		long long _n=0;
		double h=(mi+ma)/2;
		for(int i=0;i<n;i++){
			_n+=v[i]/h;
		}
		if(_n>=k){
			mi=h;
		}else{
			ma=h;
		}
	}
	printf("%.9f\n",mi);
}