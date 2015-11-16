#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

long double probably(int n, int s, long long l, long long r){
	vector<long double> a(s*(n+1)+1);
	for(int i=1;i<=s;i++)a[i+s]=powl(1.0/s,n);
	for(int e=0;e<n-1;e++)for(int i=s*n;i>=0;i--){
		long double sum=0;
		for(int j=i;j<i+s;j++)sum+=a[j];
		a[i+s]=sum;
	}
	long double ret=0;
	for(;l<=min(r,(long long)s*n);l++)ret+=a[s+l];
	return ret;
}

int main(){
	long long N,L,R;
	scanf("%lld%lld%lld",&N,&L,&R);
	if(N<10000){
		printf("%.9Lf\n",probably(N,6,L,R));
	}else{
		double a=N*3.5,v=N*35.0/12,den=sqrt(2*v);
		printf("%.9f\n",( erf((R+0.5-a)/den)-erf((L-0.5-a)/den) )/2);
	}
}