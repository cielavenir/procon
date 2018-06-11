#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
	int n,r=0;
	scanf("%d",&n);
	vector<int> v(n);
	for(int i=0;i<n;i++)scanf("%d",&v[i]);
	sort(v.begin(),v.end());
	do{
		int s=0;
		for(int i=0;i<n/2;i++)s+=v[i]^v[i+n/2];
		r=max(s,r);
		reverse(v.begin()+n/2,v.end());
	}while(next_permutation(v.begin(),v.end()));
	printf("%d\n",r);
}
