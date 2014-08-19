#include <cstdio>
#include <set>
using namespace std;
main(){
	int n,i,j,a,b;
	double r,x,y;
	set<pair<int,int> >s;
	for(scanf("%d%lf",&n,&r);n--;){
		scanf("%lf%lf",&x,&y),a=x/r,b=y/r;
		for(i=-1;i<=1;i++)for(j=-1;j<=1;j++)if(s.find(make_pair(a+i,b+j))!=s.end())goto next;
		s.insert(make_pair(a,b));
		next:;
	}
	printf("%d\n",s.size());
}