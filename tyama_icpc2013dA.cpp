#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
struct C{bool operator()(pii a,pii b){
	int x=a.first*a.first+a.second*a.second;
	int y=b.first*b.first+b.second*b.second;
	if(x!=y)return x<y;
	return a.first<b.first;
}};
main(){
	int i,j,h,w;
	vector<pii>v;
	vector<pii>::iterator it;
	for(i=1;i<999;i++)for(j=i+1;j<999;j++)v.push_back(make_pair(i,j));
	sort(v.begin(),v.end(),C());
	for(;scanf("%d%d",&h,&w),h;printf("%d %d\n",it->first,it->second))it=++find(v.begin(),v.end(),make_pair(h,w));
}