#include <cstdio>
#include <vector>
using namespace std;
int main(){
	int N,S,R=0,s=0;
	scanf("%d%d",&N,&S);
	vector<int>v(N);
	for(int i=0;i<N;i++)scanf("%d",&v[i]);
	int start=0,stop=0;
	for(;;){
		for(;stop<N&&s<S;stop++)s+=v[stop];
		if(s<S)break;
		for(;start<N&&s>=S;start++)s-=v[start];
		R=R?min(R,stop-start+1):stop-start+1;
	}
	printf("%d\n",R);
}
