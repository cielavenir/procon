#include <unordered_map>
#include <queue>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(){
	unordered_map<int,vector<int> >h;
	int N;

	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		h[a].push_back(b);
		h[b].push_back(a);
	}
	queue<int>q;
	q.push(1);
	unordered_map<int,int>depth,prev;
	depth[1]=0;
	prev[1]=-1;
	for(;!q.empty();){
		int cur=q.front();q.pop();
		for(auto &e:h[cur])if(e!=prev[cur]){
			if(depth.find(e)!=depth.end()){
				int l=depth[cur]+depth[e]+1;
				printf("%d %d\n",1+l/N,N-l%2);
				return 0;
			}
			q.push(e);
			depth[e]=depth[cur]+1;
			prev[e]=cur;
		}
	}	
}