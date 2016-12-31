#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
	int n,m,r=0;
	scanf("%d%d",&n,&m);
	vector<int>v(m);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[i]=max(n-a,0);
	}
	sort(v.begin(),v.end());
	for(int i=0;i<m-1;i++)r+=v[i];
	printf("%d\n",r);
	return 0;
}
