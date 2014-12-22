#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef pair<int,int> pii;
int main(){
	int t,c,l,x,i;
	for(scanf("%d",&t);t--;){
		vector<pii> v;
		for(i=1,scanf("%d%d",&c,&l);i<=l;i++)scanf("%d",&x),v.push_back(make_pair(x,i));
		sort(v.begin(),v.end());
		for(i=0;i<l;i++){
			vector<pii>::iterator it=lower_bound(v.begin()+(i+1),v.end(),make_pair(c-v[i].first,0));
			if(v[i].first+it->first==c){
				if(v[i].second>it->second)swap(v[i].second,it->second);
				printf("%d %d\n",v[i].second,it->second);
				break;
			}
		}
	}
}