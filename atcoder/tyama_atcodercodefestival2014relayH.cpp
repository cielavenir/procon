#include <vector>
#include <algorithm>
#include <cstdio>
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	std::vector<int>v(m);
	for(int i=0;i<m;i++)scanf("%d",&v[i]);
	int idx1=0,idx2=0,ma=0;
	for(;idx1<m;idx1++){
		for(;idx2<m&&v[idx2]-v[idx1]<=n;idx2++);
		ma=std::max(ma,idx2-idx1);
	}
	printf("%d\n",ma);
}