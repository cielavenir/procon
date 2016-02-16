//template is funny
int main(){
	void f();
	f();
}

#include <vector>
#include <cstdio>
using namespace std;

void f(){
	int N,Q;
	scanf("%d%d",&N,&Q);
	vector<vector<int> >v(N);
	for(int i=0;i<N;i++){
		int M;
		scanf("%d",&M);
		v[i].resize(M);
		for(int j=0;j<M;j++)scanf("%d",&v[i][j]);
	}
	for(int i=0;i<Q;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",v[a][b]);
	}
}