#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int N;
	scanf("%d",&N);
	vector<int>v(N);
	for(int i=0;i<N;i++)scanf("%d",&v[i]);
	sort(v.begin(),v.end());
	int r=1,c=v[0];
	for(int i=1;i<N;i++){
		if(v[i]-c>4)r++,c=v[i];
	}
	printf("%d\n",r);
}