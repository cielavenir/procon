#include <vector>
#include <cstdio>
using namespace std;

int main(){
	int N,R=1<<29;
	scanf("%d",&N);
	vector<int>v(N);
	for(int i=0;i<N;i++)scanf("%d",&v[i]);
	for(int p=0;p<=v[0];p++){
		int cur=v[0]-p,r=p;
		for(int i=0;i<N-1;i++){
			r+=cur*2;
			cur=max(v[i+1]-cur,0);
		}
		R=min(R,r+cur);
	}
	printf("%d\n",R);
}
