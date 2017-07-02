#include <vector>
#include <cstdio>
using namespace std;

int main(){
	int N,M,a,b;
	for(;~scanf("%d%d",&N,&M)&&N&&M;){
		vector<int>v(M);
		for(int i=0;i<N;i++){
			scanf("%d%d",&a,&b);
			v[a-1]=max(b,v[a-1]);
		}
		int s=0;
		for(int i=0;i<M;i++)s+=v[i];
		printf("%d\n",s);
	}
}
