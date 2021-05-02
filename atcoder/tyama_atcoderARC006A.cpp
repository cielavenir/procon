#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int b,x,i=0;
	set<int>e,l,r;
	for(;i<6;i++)scanf("%d",&x),e.insert(x);
	for(scanf("%d",&b),i=0;i<6;i++)scanf("%d",&x),l.insert(x);
	set_intersection(e.begin(),e.end(),l.begin(),l.end(),inserter(r,r.end()));
	printf("%d\n",r.size()==6?1:r.size()==5?(find(l.begin(),l.end(),b)!=l.end()?2:3):r.size()==4?4:r.size()==3?5:0);
}