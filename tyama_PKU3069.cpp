#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int R,N;
	for(;scanf("%d%d",&R,&N),~N;){
		vector<int>v(N);
		for(int i=0;i<N;i++)scanf("%d",&v[i]);
		sort(v.begin(),v.end());
		int ret=0;
		for(int i=0;i<N;ret++){
			int s=v[i++];
			for(;i<N&&v[i]<=s+R;i++);
			int p=v[i-1];
			for(;i<N&&v[i]<=p+R;i++);
		}
		printf("%d\n",ret);
    }
}