#include <deque>
#include <numeric>
#include <cstdio>
using namespace std;
int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	deque<int>v(N);
	iota(v.begin(),v.end(),1);
	for(;M--;){
		int a,x;
		scanf("%d",&a);a--;
		x=v[a];
		v.erase(v.begin()+a);
		v.push_front(x);
	}
	printf("%d\n",v[0]);
}