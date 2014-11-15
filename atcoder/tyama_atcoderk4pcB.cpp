#include <set>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(){
	int n;
	long long m,r=0,x;
	scanf("%d%lld",&n,&m);
	set<long long>se;
	se.insert(m);
	for(;n--;){
		scanf("%lld",&m);
		set<long long>::iterator it=se.lower_bound(m);
		x=abs(*it-m);
		if(it!=se.begin())x=min(x,abs(*--it-m));
		r+=x;
		se.insert(m);
	}
	printf("%lld\n",r);
}