#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int N,T,t=1,n=0,r=0,x,y,i=0;
	vector<pair<int,int> >v;
	for(scanf("%d%d",&N,&T);i<N;i++)scanf("%d%d",&x,&y),v.push_back(make_pair(x,y));
	sort(v.begin(),v.end());
	for(;n<N&&t<=T;r++){
		for(x=0;n<N&&v[n].first<=t;n++)if(v[n].second>x)x=v[n].second;
		if(!x)break;
		t=x+1;
	}
	printf("%d\n",t>T?r:-1);
}