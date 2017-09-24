#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
	int n,a,b;
	scanf("%d%d%d",&n,&n,&n);
	vector<pair<int,int> >v;
	multiset<int>se;
	for(int i=0;i<n;i++){
		scanf("%d%d",&a,&b);
		v.push_back(make_pair(a,b));
		se.insert(b);
	}
	sort(v.begin(),v.end());
	int r=min(v.rbegin()->first,*se.rbegin());
	for(int i=0;i<n-1;i++){
		se.erase(se.find(v[i].second));
		r=min(r,v[i].first+*se.rbegin());
	}
	printf("%d\n",r);
}
