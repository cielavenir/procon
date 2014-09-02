#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int T,N,M,K;
	for(scanf("%d",&T);T--;){
		scanf("%d%d%d",&N,&M,&K);
		string s=string(N,'H')+string(M,'V');
		for(;K--;)next_permutation(s.begin(),s.end());
		puts(s.c_str());
	}
}