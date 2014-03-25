#include <set>
#include <cstdio>
using namespace std;
int main(){
	set<int> se;
	int n,i,j;
	for(i=1;i<=40000;i++)se.insert(i*i);
	for(scanf("%d",&n);n--;){
		scanf("%d%d",&i,&j);
		printf("%d\n",distance(se.lower_bound(i),se.upper_bound(j)));
	}
}