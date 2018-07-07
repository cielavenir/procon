#include <vector>
#include <cstdio>
using namespace std;

vector<long long> f(int n){
	vector<long long>r(n);
	for(auto &e:r)scanf("%lld",&e);
	int k=0;
	for(int i=0;i<60;i++){
		int j=k;
		for(j=k;j<n&&!(r[j]&1LL<<i);j++);
		if(j==n)continue;
		swap(r[k],r[j]);
		for(j=0;j<n;j++)if(j-k&&r[j]&1LL<<i)r[j]^=r[k];
		k++;
	}
	r.resize(k);
	return r;
}

int main(){int n;scanf("%d",&n);puts(f(n)==f(n)?"Yes":"No");}
