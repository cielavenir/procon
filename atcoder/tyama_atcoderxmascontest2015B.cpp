#include <set>
#include <queue>
#include <cstdio>
using namespace std;
int main(){
	int N,M,a,b;
	set<pair<int,int>>broken;
	for(scanf("%d%d",&N,&M);M--;){
		scanf("%d%d",&a,&b);
		broken.emplace(a,b);
		broken.emplace(b,a);
	}
	set<int>vertex;
	for(a=2;a<=N;a++)vertex.insert(a);
	set<pair<int,int>>edges;
	queue<int>q;
	q.push(1);
	for(;!q.empty();){
		int x=q.front();q.pop();
		for(auto it=vertex.begin();it!=vertex.end();){
			if(broken.find({x,*it})==broken.end()){
				edges.emplace(x,*it);
				q.push(*it);
				auto it2=it;
				++it2;
				vertex.erase(*it);
				it=it2;
			}else{
				++it;
			}
		}
	}
	if(edges.size()<N-1){
		puts("No");
	}else{
		puts("Yes");
		for(auto &e:edges)printf("%d %d\n",e.first,e.second);
	}
}