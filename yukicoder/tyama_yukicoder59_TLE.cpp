#include <set>
#include <cstdio>
int main(){
	std::multiset<int>se;
	int N,K;
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++){
		int n;
		scanf("%d",&n);
		if(n>0){
			auto it=se.lower_bound(n);
			if(std::distance(it,se.end())<K)se.insert(it,n);
		}else{
			auto it=se.lower_bound(-n);
			if(*it==-n)se.erase(it);
		}
	}
	printf("%d\n",se.size());
}