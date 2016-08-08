#include<vector>
#include<cstdio>
using namespace std;
typedef vector<vector<pair<int,long long>>>G;
void H(G&g,int p,vector<long long>&d){
	for(auto &e:g[p])if(d[e.first]<0)d[e.first]=d[p]+e.second,H(g,e.first,d);
}
int main(){
	int N,a,b,c,i,t1=0,t2=0;scanf("%d",&N);
	G g(N);vector<long long>d0(N,-1),d1(N,-1),d2(N,-1);
	for(i=0;i<N-1;i++)scanf("%d%d%d",&a,&b,&c),g[--a].emplace_back(--b,c),g[b].emplace_back(a,c);
	d0[0]=0;H(g,0,d0);
	for(i=0;i<N;i++)if(d0[t1]<d0[i])t1=i;
	d1[t1]=0;H(g,t1,d1);
	for(i=0;i<N;i++)if(d1[t2]<d1[i])t2=i;
	d2[t2]=0;H(g,t2,d2);
	for(i=0;i<N;i++)printf("%d\n",d1[i]>d2[i]||(t1<t2&&d1[i]==d2[i]) ? t1+1 : t2+1);
}