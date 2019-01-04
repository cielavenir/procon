#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
template<typename K>
using tree = __gnu_pbds::tree<K,__gnu_pbds::null_type,std::less<K>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;

#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

vector<vector<int> >v;
tree<int>a;
long long dfs(int cur){
	int k=a.order_of_key(cur);
	long long r=k;
	a.insert(cur);
	for(auto &e:v[cur])r+=dfs(e);
	a.erase(a.find(cur));
	return r;
}

int main(){
	int N,x;
	scanf("%d",&N);
	v.resize(N);
	for(int i=1;i<N;i++)scanf("%d",&x),v[x].push_back(i);
	printf("%lld\n",dfs(0));
}
