#include <complex>
#include <vector>
#include <set>
#include <cstdio>
using namespace std;

const double EPS = 1e-12;
typedef complex<double> P;

long long pow_binary_mod(long long x,long long y,long long M){
	long long z=1;
	for(;y;y>>=1){
		if((y&1)!=0)z=z*x%M;
		x=x*x%M;
	}
	return z;
}

int main(){
	int M=998244353;
	int N,x,y;
	scanf("%d",&N);
	vector<P>v(N);
	int r=pow_binary_mod(2,N,M);
	set<pair<int,int>>se;
	for(int i=0;i<N;i++)scanf("%d%d",&x,&y),v[i]={(double)x,(double)y};
	for(int i=0;i<N;i++)for(int j=i+1;j<N;j++){
		if(se.find({i,j})!=se.end())continue;
		vector<int>x={i,j};
		for(int k=j+1;k<N;k++)if(abs(imag(conj(v[j]-v[k])*(v[i]-v[k])))<1e-12)x.push_back(k);
		for(int a=0;a<x.size();a++)for(int b=a+1;b<x.size();b++){
			r=(r-pow_binary_mod(2,b+~a,M))%M;
			se.emplace(x[a],x[b]);
		}
	}
	printf("%d\n",((r-N-1)%M+M)%M);
}
