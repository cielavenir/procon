#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int T,h,m;
	vector<int>v;
	for(;~scanf("%d",&T);){
		for(;T--;)scanf("%d%d",&h,&m),v.push_back(h*60+m);
	}
	sort(v.begin(),v.end());
	printf("%d:%02d",v[0]/60,v[0]%60);
	int prev=v[0];
	for(int i=0;i<v.size();i++){
		if(prev==v[i])continue;
		prev=v[i];
		printf(" %d:%02d",v[i]/60,v[i]%60);
	}
	puts("");
}