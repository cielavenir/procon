#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int n,m,a,b;
	vector< pair<int,int> >v;
	for(scanf("%d%d",&m,&n);n--;v.push_back(make_pair(b,a)))scanf("%d%d",&a,&b);
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	for(a=b=0;a<v.size();a++)
		if(m<v[a].second){b+=m*v[a].first;break;}else b+=v[a].second*v[a].first,m-=v[a].second;
	printf("%d\n",b);
}