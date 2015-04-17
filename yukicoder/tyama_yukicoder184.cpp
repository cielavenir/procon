#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

int gauss(vector<vector<int> > &a){
	if(a.empty())return 0;
	int w=a[0].size();
	int n=a.size();
	int ret=0;
	for(int i=0;i<w;i++){
		if(!a[ret][i]){
			int j=ret+1;
			for(;j<n;j++){
				if(a[j][i]){
					for(int k=ret;k<w;k++)a[ret][k]^=a[j][k];
					break;
				}
			}
			if(j==n)continue;
		}
		for(int j=ret+1;j<n;j++){
			if(a[j][i])for(int k=ret;k<w;k++)a[j][k]=a[j][k]^a[ret][k];
		}
		if(++ret==n)break;
	}
	return ret;
}

int main(){
	int N;
	scanf("%d",&N);
	vector<vector<int> >v(N);
	for(int i=0;i<N;i++){
		v[i].resize(64);
		long long n;
		scanf("%lld",&n);
		for(int j=0;n;n/=2,j++)v[i][j]=n%2;
	}
	printf("%lld\n",1LL<<gauss(v));
}