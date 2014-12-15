#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int N,r=0;
	scanf("%d",&N);
	std::vector<int>v(N);
	for(int i=0;i<N;i++)scanf("%d",&v[i]);
	for(int i=0;i<N;i++){
		auto ma=max_element(v.begin(),v.end()-i);
		if(ma!=v.begin()+(N-1-i)){
			r+=*ma+v[N-1-i];
			swap(*ma,v[N-1-i]);
		}
		auto mi=min_element(v.begin()+i,v.end());
		if(mi!=v.begin()+i){
			r+=*mi+v[i];
			swap(*mi,v[i]);
		}
	}
	printf("%d\n",r);
}