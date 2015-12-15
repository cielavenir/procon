#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int N,M,P,r=1<<29;
	scanf("%d%d%d",&N,&M,&P);
	vector<int>v(M+1);
	for(int i=0;i<M;i++)scanf("%d",&v[i]);
	v[M]=P;
	M++;
	sort(v.begin(),v.end());
	int idx=distance(v.begin(),lower_bound(v.begin(),v.end(),P));
	for(int i=0;i<M;i++){
		//unused section=v[i]..v[i+1]
		r=min(r,min(
			(v[i]-v[idx]+N)%N+(v[i]-v[(i+1)%M]+N)%N,
			(v[idx]-v[(i+1)%M]+N)%N+(v[i]-v[(i+1)%M]+N)%N
		));
	}
	printf("%d\n",r*100);
}