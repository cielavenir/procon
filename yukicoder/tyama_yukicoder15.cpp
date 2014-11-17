#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int n;
	long long s;
	scanf("%d%lld",&n,&s);
	vector<long long>v(n);
	for(int i=0;i<n;i++)scanf("%lld",&v[i]);
	if(n==1){
		if(v[0]==s)puts("1");
		return 0;
	}
	int mid=n/2;
	multimap<long long,vector<int> >mm;
	for(int i=0;i<1<<mid;i++){
		long long val=0;
		vector<int>lst;
		for(int j=0;j<mid;j++)if(i&(1<<j)){
			val+=v[j];
			lst.push_back(j+1);
		}
		mm.insert(make_pair(val,lst));
	}
	vector<vector<int> >result;
	for(int i=0;i<1<<(n-mid);i++){
		long long val=0;
		vector<int>lst;
		for(int j=0;j<(n-mid);j++)if(i&(1<<j)){
			val+=v[mid+j];
			lst.push_back(mid+j+1);
		}
		auto it=mm.equal_range(s-val);
		for(;it.first!=it.second;++it.first){
			vector<int>x=it.first->second;
			x.insert(x.end(),lst.begin(),lst.end());
			result.push_back(x);
		}
	}
	sort(result.begin(),result.end());
	for(auto &e:result){
		for(int i=0;i<e.size();i++){
			printf(i<e.size()-1?"%d ":"%d\n",e[i]);
		}
	}
}