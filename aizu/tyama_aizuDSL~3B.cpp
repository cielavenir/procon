#include <cstdio>
#include <vector>
using namespace std;
int main(){
	int N,K,R=0,k=0;
	scanf("%d%d",&N,&K);
	vector<int>v(N),b(K+1);
	for(int i=0;i<N;i++)scanf("%d",&v[i]);
	int start=0,stop=0;
	for(;;){
		for(;stop<N&&k<K;stop++){
			if(v[stop]<=K&&++b[v[stop]]==1)k++;
		}
		if(k<K)break;
		for(;start<N&&k>=K;start++){
			if(!R||R>stop-start)R=stop-start;
			if(v[start]<=K&&!--b[v[start]])k--;
		}
	}
	printf("%d\n",R);
}
