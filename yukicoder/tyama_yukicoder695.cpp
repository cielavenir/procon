#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int solve(int n,int M,const vector<int> &x){
	int m=n/2,r=0;
	vector<int> v(n-m);v[0]=1;
	for(int i=1;i<n-m;i++)for(auto &e:x){
		if(e<=i)v[i]=(v[i]+v[i-e])%M;
	}
	for(auto &e:x)for(int i=max(m-e,0);i<min(n-e,m);i++){
		r=(r+1LL*v[i]*v[n-i-e-1])%M;
	}
	return r;
}

long long pow(long long x,long long y,long long M){
	long long z=1;
	for(;y;y>>=1){
		if(y&1)z=z*x%M;
		x=x*x%M;
	}
	return z;
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	vector<int>x(m);
	for(int i=0;i<m;i++)scanf("%d",&x[i]);
	int M1=168647939,M2=592951213;
	int R1=solve(n,M1,x),R2=solve(n,M2,x);
	long long Rm=(R2-R1+M2)*pow(M1,M2-2,M2)%M2;
	printf("%lld\n",Rm*M1+R1);
}
