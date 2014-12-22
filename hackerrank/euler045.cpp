#include <unordered_map>
#include <cstdio>
using namespace std;
typedef unsigned long long (*F)(unsigned long long);
unordered_map<int,F> t={
	{3,[](unsigned long long n){return n*(n+1)/2;}},
	{5,[](unsigned long long n){return n*(3*n-1)/2;}},
	{6,[](unsigned long long n){return n*(2*n-1);}},
};
int main(){
	unsigned long long N;
	int A,B;
	scanf("%llu%d%d",&N,&A,&B);
	F a=t[A];
	F b=t[B];
	unsigned long long n=1,m=1;
	for(;a(n)<N;){
		for(;a(n)<b(m);)n++;
		for(;a(n)>b(m);)m++;
		if(a(n)<N&&a(n)==b(m))printf("%llu\n",a(n)),m++;
	}
}