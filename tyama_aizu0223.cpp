#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
#define Z(n)get<n>(z)
#define M make_pair
#define F first
#define S second
using namespace std;
typedef pair<int,int> pii;
typedef tuple<pii,pii,int> T;
int t[51][51],dx[]={-1,0,1,0},dy[]={0,-1,0,1},a,b,x,y,X,Y,i,j,k;
int main(){
	for(;scanf("%d%d",&a,&b),a;){
		map<pair<pii,pii>,int>m;
		scanf("%d%d%d%d",&x,&y,&X,&Y);x--,y--,X--,Y--;
		for(j=0;j<b;j++)for(i=0;i<a;i++)scanf("%d",t[i]+j);
		queue<T>q;
		m[M(M(x,y),M(X,Y))]=1;
		for(q.push(make_tuple(M(x,y),M(X,Y),0));!q.empty();){
			T z=q.front();q.pop();
			if(Z(0)==Z(1)){printf("%d\n",get<2>(z));goto OK;}
			if(Z(2)<100)for(i=0;i<4;i++){k=0;
				pii c1=make_pair(Z(0).F+dx[i],Z(0).S+dy[i]);
				if(!(0<=c1.F&&c1.F<a&&0<=c1.S&&c1.S<b&&!t[c1.F][c1.S]))c1=Z(0),k|=1;
				pii c2=make_pair(Z(1).F+dx[(i+2)%4],Z(1).S+dy[(i+2)%4]);
				if(!(0<=c2.F&&c2.F<a&&0<=c2.S&&c2.S<b&&!t[c2.F][c2.S]))c2=Z(1),k|=2;
				if(k<3&&!m[M(c1,c2)]){
					q.push(make_tuple(c1,c2,Z(2)+1));
					m[M(c1,c2)]=1;
				}
			}
		}
		puts("NA");
		OK:;
	}
}