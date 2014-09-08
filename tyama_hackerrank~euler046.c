#include <vector>
#include <cstdio>
using namespace std;

int main(){
	const int M=500000;
	vector<int> P;
	vector<int> sieve(M+1);
	for(int i=2;i<=M;i++)if(!sieve[i]){
		P.push_back(i);
		for(int j=i*2;j<=M;j+=i)sieve[j]=1;
	}
	vector<int> ret(M+1);
	for(int p:P){
		for(int i=1;p+2*i*i<=M;i++)ret[p+2*i*i]++;
	}
	int t,n;
	for(scanf("%d",&t);t--;printf("%d\n",ret[n]))scanf("%d",&n);
}