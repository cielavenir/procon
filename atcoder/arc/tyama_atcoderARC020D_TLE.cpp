#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int n,m,k,s;
	scanf("%d%d%d",&n,&m,&k);
	if(n>12)return 1;
	vector<int> d0(n-1);
	for(int i=0;i<n-1;i++)scanf("%d",&d0[i]);
	vector<vector<int> >a(n);
	vector<int>b(n);
	for(int i=0;i<n;i++)a[i].resize(n),b[i]=i;
	for(int i=0;i<n-1;i++)a[i+1][i]=a[i][i+1]=d0[i];
	for(int i=2;i<n;i++)for(int j=i-2;j>=0;j--){
		a[i][j]=a[j][i]=a[i-1][j]+a[i-1][i];
	}
	int r=0;
	do{
		s=0;
		for(int i=0;i<k-1;i++)s+=a[b[i]][b[i+1]];
		if(s%m==0)r=(r+1)%1000000007;
		//next_partial_permutation: http://origin.googlecode.com/svn-history/r366/trunk/core/include/origin/algorithm/boost_combination.hpp
		//if(!k)break;
		reverse(b.begin()+k,b.end());
	}while(next_permutation(b.begin(),b.end()));
	printf("%d\n",r);
}