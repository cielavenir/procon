#include <vector>
#include <cstdio>
using namespace std;
int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	vector<int>target(M);
	for(int i=0;i<M;i++)scanf("%d",&target[i]),target[i]--;
	vector<int>points(N);
	for(int i=0;i<M;i++){
		int diff=0;
		for(int j=0;j<N;j++){
			int x;
			scanf("%d",&x);x--;
			if(x!=target[i])diff++;
			else points[j]++;
		}
		points[target[i]]+=diff;
	}
	for(int i=0;i<N;i++)printf("%d\n",points[i]);
}