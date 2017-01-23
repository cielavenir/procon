#include <random>
#include <vector>
#include <cstdio>
#include <ctime>
#include <unistd.h>
using namespace std;
int main(){
	uniform_int_distribution<int> distribution(0,1);
	mt19937_64 engine((unsigned int)time(NULL)^(getpid()<<16));
	int N,i,j,k;
	for(;~scanf("%d",&N)&&N;){
	vector<vector<vector<long long>>>M(3);
	for(auto &e:M)for(e.resize(N),i=0;i<N;i++)for(e[i].resize(N),j=0;j<N;j++)scanf("%lld",&e[i][j]);
	for(k=9;--k;){
		vector<int>v(N),x(N),y(N),z(N);
		for(j=0;j<N;j++)v[j]=distribution(engine);
		for(i=0;i<N;i++)for(j=0;j<N;j++){
			z[i]+=M[1][i][j]*v[j];
		}
		for(i=0;i<N;i++)for(j=0;j<N;j++){
			x[i]+=M[0][i][j]*z[j];
			y[i]+=M[2][i][j]*v[j];
		}
		if(x!=y){puts("NO");break;}
	}
	if(!k)puts("YES");
	}
}
/*
atcoderkupc2012prD: 3,1,0,2
live4956: 2,0,0,1
*/
