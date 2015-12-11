#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int N;
	scanf("%d",&N);
	vector<long long>v(N);
	for(int i=0;i<N;i++)scanf("%lld",&v[i]);
	int r=0;
	long long n=0,c=0;
	for(int i=0;i<N;i++){
		c+=v[i];
		if(c>=n)r++,n=c,c=0;
	}
	printf("%d\n",r);
}

/*
Corner Case:
4
2 1 4 4
=> 3
*/