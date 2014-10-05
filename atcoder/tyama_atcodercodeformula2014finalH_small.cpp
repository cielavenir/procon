#include <vector>
#include <cstdio>
using namespace std;

int main(){
	long long r=0;
	int n,s1,s2;
	scanf("%d%d%d",&n,&s1,&s2);
	if(n>10000)return 1;
	vector<pair<int,int> >v(n);
	for(int i=0;i<n;i++)scanf("%d%d",&v[i].first,&v[i].second);
	for(int i=0;i<n-1;i++)for(int j=i+1;j<n;j++){
		long long d=(long long)(v[i].first-v[j].first)*(long long)(v[i].second-v[j].second);
		if(s1<=d&&d<=s2)r++;
	}
	printf("%lld\n",r);
}