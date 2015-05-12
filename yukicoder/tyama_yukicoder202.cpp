#include <vector>
#include <set>
#include <cstdio>
using namespace std;
typedef pair<int,int> pii;

int main(){
	int N;
	scanf("%d",&N);
	vector<pair<int,int> >v(N);
	set<int>kindx,kindy;
	for(int i=0;i<N;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		v[i]={x,y};
		kindx.insert(x),kindy.insert(y);
	}
	//x must be more sparse (wide) than y
	if(kindx.size()<kindy.size())for(int i=0;i<N;i++)swap(v[i].first,v[i].second);

	set<pii>se;
	for(int i=0;i<N;i++){
		int x=v[i].first,y=v[i].second;
		pii A={x-20,0},B={x+20,1<<30};
		auto a=se.lower_bound(A),b=se.upper_bound(B);
		for(;a!=b;++a)if((a->first-x)*(a->first-x) + (a->second-y)*(a->second-y) < 400)break;
		if(a==b)se.insert({x,y});
	}
	printf("%d\n",se.size());
}