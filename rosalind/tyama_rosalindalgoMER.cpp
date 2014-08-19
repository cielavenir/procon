#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
int main(){
	int n,m,i,x;
	vector<int>a;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&x),a.push_back(x);
	scanf("%d",&m);
	for(i=0;i<m;i++)scanf("%d",&x),a.push_back(x);
	sort(a.begin(),a.end());
	for(i=0;i<a.size();i++)printf(i==a.size()-1?"%d\n":"%d ",a[i]);
}