#include <queue>
#include <map>
#include <cstdio>
using namespace std;

int main(){
	int s,g;
	scanf("%d%d",&s,&g);
	map<int,int>m;
	m[s]=0;
	queue<int>q;
	for(q.push(s);;){
		int cur=q.front();q.pop();
		if(cur>1)if(m.find(cur-1)==m.end())m[cur-1]=m[cur]+1,q.push(cur-1);
		if(m.find(cur*2)==m.end())m[cur*2]=m[cur]+1,q.push(cur*2);
		if(m.find(g)!=m.end()){
			printf("%d\n",m[g]);
			return 0;
		}
	}
}