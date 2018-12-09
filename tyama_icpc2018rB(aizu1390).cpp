#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int N;
	scanf("%d",&N);
	vector<int>a(N);
	set<int>h;
	int r=2;
	for(int i=0;i<N;i++)scanf("%d",&a[i]),h.insert(a[i]);
	sort(a.begin(),a.end());
	for(int i=0;i<N;i++)for(int j=i+1;j<N;j++){
		int d=a[j]-a[i];
		int k=2;
		for(;;k++)if(h.find(a[i]+d*k)==h.end())break;
		r=max(r,k);
	}
	printf("%d\n",r);
}
