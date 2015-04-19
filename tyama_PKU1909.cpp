#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
int N, P[10001], M[10001], V[10001];
int main(){
	for(;~scanf("%d",&N)&&N;){
		fill(P, P+N, -1);
		int id, c;
		for(int i=0;i<N;++i){
			scanf("%d", &id); --id; // [1,N] を [0,N-1] に
			scanf("%d%d", M+id, V+id); // marble の数, vertex の数
			M[id]--;
			for (int j=0;j<V[id];++j){
				scanf("%d", &c); --c; // id(親) c(子供)
				P[c] = id;
			}
		}
		int R=0,cnt=0;
		for(;cnt<N;)for(int i=0;i<N;++i){
			if(V[i]==0){
				M[P[i]]+=M[i];
				R+=abs(M[i]);
				V[P[i]]--;
				V[i]=-1;
				cnt++;
			}
		}
		printf("%d\n",R);
	}
}