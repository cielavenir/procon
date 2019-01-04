#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
template<typename K>
using tree = __gnu_pbds::tree<K,__gnu_pbds::null_type,std::less<K>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;

#include <cstdio>

int main(){
	tree<std::pair<long long,int> > v;
	int Q,K,c;
	long long n;
	scanf("%d%d",&Q,&K);
	for(int q=0;q<Q;q++){
		scanf("%d",&c);
		if(c==1){
			scanf("%lld",&n);
			v.insert({n,q});
		}else{
			if(v.size()<K){
				puts("-1");
			}else{
				auto it=v.find_by_order(K-1);
				printf("%lld\n",it->first);
				v.erase(it);
			}
		}
	}
}
