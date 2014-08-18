#include <stdio.h>
int main(){
	long long n,h,a,b,c,d,e,dinner;
	scanf("%lld%lld%lld%lld%lld%lld%lld",&n,&h,&a,&b,&c,&d,&e);
	long long r=n*a,t;
	//最大n_end回の普通の食事で十分である。なお、n*e-hが負になる場合に注意を要する。
	//h+n_end*b>(n-n_end)*e <=> n_end>(n*e-h)/(b+e)
	long long n_end=n*e-h;
	n_end=n_end>0 ? n_end/(b+e)+1 : 0;
	for(dinner=0;dinner<=n_end;dinner++){
		//h+dinner*b+supper*d>(n-dinner-supper)*e <=> supper>((n-dinner)*e-dinner*b-h)/(d+e)
		long long supper=(n-dinner)*e-dinner*b-h;
		supper=supper>0 ? supper/(d+e)+1 : 0;
		t=dinner*a+supper*c;
		if(r>t)r=t;
	}
	printf("%lld\n",r);
	return 0;
}