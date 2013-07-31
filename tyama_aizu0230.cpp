#include <queue>
#include <tuple>
#include <cstdio>
#include <cstring>
using namespace std;
#define SENTINEL 99999
typedef tuple<int,int,int> tiii; //building, floor, depth
int M[2][101],B[2][101],n;
int bfs(int i){
	memset(M,99,sizeof(M));
	queue<tiii> q;
	q.push(make_tuple(i,0,0));M[i][0]=0;
	for(;!q.empty();){
		tiii t=q.front();q.pop();
		int building=get<0>(t);
		int floor=get<1>(t);
		int depth=get<2>(t);
		for(;B[building][floor]==1&&B[building][floor+1]==1;){
			if(M[building][floor+1]>M[building][floor])M[building][floor+1]=M[building][floor];
			floor++;
		}
		for(;B[building][floor]==2;){
			if(M[building][floor-1]>M[building][floor])M[building][floor-1]=M[building][floor];
			floor--;
		}
		if(floor==n-1)return depth;
		for(i=2;i>=0;i--)if(floor+i<n&&M[building^1][floor+i]>M[building][floor]){
			M[building^1][floor+i]=M[building][floor];
			q.push(make_tuple(building^1,floor+i,depth+1));
		}
	}
	return SENTINEL;
}
int main(){
	int i,j;
	for(;scanf("%d",&n),n;){
		for(j=0;j<2;B[j][i]=0,j++)for(i=0;i<n;i++)scanf("%d",B[j]+i);
		i=min(bfs(0),bfs(1));
		printf(i==SENTINEL?"NA\n":"%d\n",i);
	}
}