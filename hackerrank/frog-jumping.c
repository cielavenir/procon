#include <stdio.h>
int main(){
	const int D=5;
	long long N;
	int s=0;
	scanf("%lld",&N);
	if(N<0)N=-N;
	for(;N;){
		if(N%D>=3){
			s+=D-N%D;
			N=N/D+1;
		}else{
			s+=N%D;
			N/=D;
		}
	}
	printf("%d\n",s);
	return 0;
}