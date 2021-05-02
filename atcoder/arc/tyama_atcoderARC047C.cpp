#include<deque>
#include<numeric>
#include<cstdio>
using namespace std;
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	deque<int>v(n);
	iota(v.begin(),v.end(),1);
	long long x=1,y;
	for(int i=0;i<n;i++){
		y=(x*(n-i)-1)/k;
		printf("%d\n",v[y]);
		v.erase(v.begin()+y);
		x=(x*(n-i)-1)%k+1;
	}
}