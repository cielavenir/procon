#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	vector<int>n(N),m(M);
	for(int i=0;i<N;i++)scanf("%d",&n[i]);
	for(int i=0;i<M;i++)scanf("%d",&m[i]);
	sort(n.begin(),n.end());
	sort(m.begin(),m.end());
	vector<int>x,y;
	set_intersection(n.begin(),n.end(),m.begin(),m.end(),back_inserter(x));
	set_union(n.begin(),n.end(),m.begin(),m.end(),back_inserter(y));
	printf("%f\n",x.size()*1.0/y.size());
}