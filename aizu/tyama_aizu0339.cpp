#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
	set<vector<int> >se;
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		vector<int>v(3);
		scanf("%d%d%d",&v[0],&v[1],&v[2]);
		sort(v.begin(),v.end());
		se.insert(v);
	}
	printf("%d\n",N-se.size());
}
