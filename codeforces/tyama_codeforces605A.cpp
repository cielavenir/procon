#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	vector<pair<int,int> > x(n);
	for(int i=0;i<n;i++)scanf("%d",&x[i].first),x[i].second=i;
	sort(x.begin(),x.end());
	int r=1,c=x[0].second,R=1;
	for(int i=1;i<n;i++){
		r=c<x[i].second?r+1:1;
		if(x[i-1].first!=x[i].first)c=x[i].second;
		if(R<r)R=r;
	}
	printf("%d\n",n-R);
}