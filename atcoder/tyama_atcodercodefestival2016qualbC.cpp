#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int w,h,n,i;
	long long r=0,f;
	scanf("%d%d",&w,&h);
	n=w+h;
	vector<pair<int,int> >node(n);
	for(i=0;i<w;i++)scanf("%d",&node[i].first),node[i].second=0;
	for(;i<n;i++)scanf("%d",&node[i].first),node[i].second=1;
	sort(node.begin(),node.end());
	for(i=0;i<n;i++){
		if(node[i].second)f=w+1,h--;
		else f=h+1,w--;
		r+=node[i].first*f;
	}
	printf("%lld\n",r);
}
