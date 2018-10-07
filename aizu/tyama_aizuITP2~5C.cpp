#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	vector<int>v(n),w(n);
	for(int i=0;i<n;i++)scanf("%d",&v[i]),w[i]=v[i];
	if(prev_permutation(v.begin(),v.end()))for(int i=0;i<n;i++)printf(i<n-1?"%d ":"%d\n",v[i]);
	for(int i=0;i<n;i++)printf(i<n-1?"%d ":"%d\n",w[i]);
	if(next_permutation(w.begin(),w.end()))for(int i=0;i<n;i++)printf(i<n-1?"%d ":"%d\n",w[i]);
}
