#include <vector>
#include <set>
#include <cstdio>
using namespace std;
int main(){
	int N,L;
	scanf("%d%d",&N,&L);
	vector<int>v(N);
	for(int i=0;i<N;i++)scanf("%d",&v[i]);
	multiset<int>se;
	for(int i=0;i<L-1;i++)se.insert(v[i]);
	for(int i=L-1;i<N;i++){
		se.insert(v[i]);
		printf(i<N-1?"%d ":"%d\n",*se.begin());
		se.erase(se.find(v[i-L+1]));
	}
}
