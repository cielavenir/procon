#include <queue>
#include <map>
#include <cstdio>
using namespace std;
int main(){
	int T,N,L;
	for(scanf("%d",&T);T--;){
		map<int,int>m;
		for(scanf("%d",&N);N--;m[L]++)scanf("%d",&L);
		priority_queue<pair<int,int> >q;
		for(map<int,int>::iterator it=m.begin();it!=m.end();++it)q.push(make_pair(it->second,it->first));
		int r=0;
		for(;q.size()>2;r++){
			vector<pair<int,int> >v(3);
			for(int i=0;i<3;i++)v[i]=q.top(),q.pop();
			for(int i=0;i<3;i++)if(v[i].first>1)q.push(make_pair(v[i].first-1,v[i].second));
		}
		printf("%d\n",r);
	}
}