#include <queue>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef pair<
	vector<int>,
	pair<int,int>
> pvipii;
//first==circle
//second.first==tagger
//second.second==position
#define N 8
pvipii switchstate(pvipii &_state,int n){
	pvipii state=_state;
	int position=state.second.second;
	position=(position+n)%N;
	swap(state.second.first,state.first[position]);
	state.second.second=position;
	return state;
}

int main(){
	int i,j;
	map<pvipii,int>depth;
	map<pvipii,pvipii>back;
	queue<pvipii>q;
	pvipii init;
	for(i=1;i<=N;i++)init.first.push_back(i);
	depth[init]=0;
	q.push(init);
	//exhaustive BFS
	for(;!q.empty();){
		pvipii state=q.front();
		q.pop();
		for(i=0;i<N;i++){
			pvipii newstate=switchstate(state,i);
			if(depth.find(newstate)==depth.end() || depth[newstate]>depth[state]+i+N){
				q.push(newstate);
				depth[newstate]=depth[state]+i+N;
				back[newstate]=state;
			}
		}
	}
	for(map<pvipii,int>::iterator it=depth.begin();it!=depth.end();++it){
		for(j=i=0;i<N;i++)if(it->first.first[i]==N)break;
		if(i<N)for(;j<N;j++)if(it->first.first[(i+j)%N]!=N-j)break;
		if(j==N){
			printf("%d\n",it->second); //96
			if(it->second==48||it->second==96){
				pvipii state=it->first;
				for(;back.find(state)!=back.end();state=back[state]){
					for(i=0;i<N;i++)printf("%d",state.first[i]);
					printf(",%d,%d\n",state.second.first,state.second.second);
				}
			}
		}
	}
}