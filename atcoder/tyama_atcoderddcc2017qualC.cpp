#include <set>
#include <cstdio>
using namespace std;

int main(){
	int n,c,z;
	scanf("%d%d",&n,&c);
	multiset<int>se;
	for(int i=0;i<n;i++)scanf("%d",&z),se.insert(z);
	for(z=0;;z++){
		auto it=se.begin();
		if(it==se.end())break;
		auto it2=se.upper_bound(c-*it-1);
		if(it2!=se.begin()){
			--it2;
			if(it2!=it)se.erase(it2);
		}
		se.erase(it);
	}
	printf("%d\n",z);
}
