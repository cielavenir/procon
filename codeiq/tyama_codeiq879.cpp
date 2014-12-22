// http://www.checkio.org/mission/water-jars/share/617c4e941abcafc205e199a10920a2a7/ みたいな幅優先探索で。
// 問題サイズが少々大きいのでC++を採用。

#include <queue>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef pair<int,pair<int,int> >pipii;
#define make_pp(a,b,c) make_pair((a),make_pair((b),(c)))

int solve(int A,int B,int C){
	int t;
	map<pipii,pipii>back;
	queue<pipii>q;
	pipii state=make_pair(A,make_pair(0,0)),newstate;
	back[state]=state;
	q.push(state);

	for(;!q.empty();){
		state=q.front();
		q.pop();
		if(state.first<A){
			t=min(A-state.first,state.second.first);
			newstate=make_pp(state.first+t,state.second.first-t,state.second.second);
			if(back.find(newstate)==back.end()){
				back[newstate]=state;
				q.push(newstate);
				if(newstate.first==A/2)break;
			}
			t=min(A-state.first,state.second.second);
			newstate=make_pp(state.first+t,state.second.first,state.second.second-t);
			if(back.find(newstate)==back.end()){
				back[newstate]=state;
				q.push(newstate);
				if(newstate.first==A/2)break;
			}
		}
		if(state.second.first<B){
			t=min(B-state.second.first,state.first);
			newstate=make_pp(state.first-t,state.second.first+t,state.second.second);
			if(back.find(newstate)==back.end()){
				back[newstate]=state;
				q.push(newstate);
				if(newstate.first==A/2)break;
			}
			t=min(B-state.second.first,state.second.second);
			newstate=make_pp(state.first,state.second.first+t,state.second.second-t);
			if(back.find(newstate)==back.end()){
				back[newstate]=state;
				q.push(newstate);
				//if(newstate.first==A/2)break;
			}
		}
		if(state.second.second<C){
			t=min(C-state.second.second,state.first);
			newstate=make_pp(state.first-t,state.second.first,state.second.second+t);
			if(back.find(newstate)==back.end()){
				back[newstate]=state;
				q.push(newstate);
				if(newstate.first==A/2)break;
			}
			t=min(C-state.second.second,state.second.first);
			newstate=make_pp(state.first,state.second.first-t,state.second.second+t);
			if(back.find(newstate)==back.end()){
				back[newstate]=state;
				q.push(newstate);
				//if(newstate.first==A/2)break;
			}
		}
	}
	if(!q.empty()){
#if 0
		for(;back[newstate]!=newstate;newstate=back[newstate]){
			printf("%d %d %d\n",newstate.first,newstate.second.first,newstate.second.second);
		}
		printf("%d %d %d\n---\n",A,0,0);
#endif
		return true;
	}
	return false;
}

int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main(){
	int A,B,C,r=0;
	for(A=10;A<=100;A+=2){
		for(C=1;C<A/2;C++){
			B=A-C;
			if(gcd(B,C)==1)r+=solve(A,B,C);
		}
	}
	printf("%d\n",r); //514
}