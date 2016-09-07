//http://codeforces.com/gym/100917
#include <map>
#include <cstdio>
using namespace std;

map<long long,long long>memo={{1,0},{2,2}};
long long dfs(long long n){
	return memo[n] ? memo[n] : (memo[n]=n%2==0 ? dfs(n/2)+n : dfs(n/2*3+2)+n+1);
}
int main(){
	long long n;
	scanf("%lld",&n);
	printf("%lld\n",dfs(n));
}