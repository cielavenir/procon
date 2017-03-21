#include <vector>
#include <map>
#include <cstdio>
using namespace std;

int main(){
	int N,M,a,b,c;
	scanf("%d%d",&N,&M);
	vector<int>total(N);
	map<int,map<int,int> >x;
	for(int i=0;i<M;i++){
		scanf("%d%d%d",&a,&b,&c);
		total[a]+=c;
		x[a][b]=c;
	}
	vector<double>r(N,10);
	for(int c=0;c<100;c++){
		vector<double>r0(N);
		for(int i=0;i<N;i++){
			for(auto &e:x[i])r0[e.first]+=r[i]*e.second/total[i];
		}
		r=r0;
	}
	for(auto &e:r)printf("%f\n",e);
}
