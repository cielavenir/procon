#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

bool gauss(vector<vector<long double> > &a){
	if(a.empty())return false;
	int n=a.size();
	for(int i=0;i<n;i++){
		if(!a[i][i]){
			int j=i+1;
			for(;j<n;j++){
				if(a[j][i]){
					for(int k=i;k<=n;k++)a[i][k]+=a[j][k];
					break;
				}
			}
			if(j==n)return false;
		}
		for(int j=0;j<n;j++)if(i!=j){
			long double r=a[j][i]/a[i][i];
			for(int k=i;k<=n;k++)a[j][k]=a[j][k]-a[i][k]*r;
		}
	}
	for(int i=0;i<n;i++){
		long double x=a[i][i];
		for(int j=0;j<a[i].size();j++)a[i][j]/=x;
	}
	return true;
}
long long comb(int n,int k){
	if(k>n-k)k=n-k;
	long long r=1;
	for(int i=0;i<k;i++)r=r*(n-i)/(i+1);
	return r;
}
long long pow_binary(long long x,long long y){
	long long z=1;
	for(;y;y>>=1){
		if((y&1)!=0)z=z*x;
		x=x*x;
	}
	return z;
}
int main(){
	int A,M,B,N;
	for(;scanf("%d%d%d%d",&A,&M,&B,&N),A;){
		vector<vector<long double> >m(M*N+1);
		for(int i=0;i<=M*N;i++)m[i].resize(M*N+2);
		m[0][0]=m[0][M*N+1]=1;
		for(int i=0;i<=M*N;i++)for(int k=0;k<=i;k++){
			m[k%M*N+(i-k)%N+1][i<M*N ? i+1 : 0]+=(long double)comb(i,k)*pow_binary(A,k/M)*pow_binary(B,(i-k)/N);
		}
		gauss(m);
		printf("1");
		for(int i=M*N;i>0;i--)printf(" %d",(int)(roundl(m[i][M*N+1])));
		puts("");
	}
}