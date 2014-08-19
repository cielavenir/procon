#include <set>
#include <cstdio>
using namespace std;
int score[100010],show[100010];
int main(){
	set<pair<int,int> >s;
	int N,R,L,d,t,x,c=0,m,n,i;
	scanf("%d%d%d",&N,&R,&L);
	for(i=1;i<=N;i++)s.insert(make_pair(0,0));
	for(;R--;){
		scanf("%d%d%d",&d,&t,&x);
		show[s.begin()->second]+=t-c,c=t;
		s.erase(make_pair(-score[d],d));
		score[d]+=x;
		s.insert(make_pair(-score[d],d));
	}
	show[s.begin()->second]+=L-c;
	for(n=i=1,m=show[i];i<=N;i++)if(m<show[i])m=show[i],n=i;
	printf("%d\n",n);
}