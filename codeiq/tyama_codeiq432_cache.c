#include <stdio.h>
#include <string.h>
#define m_bits 20
int A[999999],W[m_bits][999999],N;
long long run(){
	int bits=m_bits,p1,p0,i;
	long long count=0,s;
	for(;bits>0&&!(N&1<<bits);bits--);
	for(;bits>=0;bits--){
		p1=1<<(bits+1);
		p0=1<<bits;
		//memset(W,0,(N/p1+1)*sizeof(int));
		for(i=0;i<N;i++){
			s=A[i]/p1;
			if(A[i]&p0)W[bits][s]++;
			else count+=W[bits][s];
		}
	}
	return count;
}
int main(){
	int T,i;
	for(N=0;~scanf("%d",A+N);N++);printf("%lld\n",run());
	return 0;
}