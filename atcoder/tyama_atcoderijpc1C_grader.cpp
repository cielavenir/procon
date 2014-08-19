#include <cstdio>
void init(int N, int A[]);
void update(int i, int x);
int train(int p, int q);

const int MAXN = 30000, MAXPQ = 20000;
static int N, M, A[MAXN];
static int qtype[MAXPQ], qa[MAXPQ], qb[MAXPQ];

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; ++i)scanf("%d", &A[i]);
	scanf("%d", &M);

	init(N, A);
	for(int i=0; i<M; ++i){
		scanf("%d%d%d", &qtype[i], &qa[i], &qb[i]);
		if(qtype[i] == 0) {
			update(qa[i], qb[i]);
		} else {
			printf("%d\n", train(qa[i], qb[i]));
		}
	}
	return 0;
}