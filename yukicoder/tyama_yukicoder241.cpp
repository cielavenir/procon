#include <vector>
#include <random>
#include <algorithm>
#include <cstdio>
#include <unistd.h>
using namespace std;
mt19937_64 engine((unsigned int)time(NULL)^(getpid()<<16));

bool validate(const vector<int>&a,const vector<int>&r){
	vector<bool>f(r.size());
	for(int i=0;i<r.size();i++){
		if(r[i]<0 || r.size()<=r[i])return false;
		if(r[i]==a[i])return false;
		if(f[r[i]])return false;
		f[r[i]]=true;
	}
	return true;
}

int main(){
	int N;
	scanf("%d",&N);
	vector<int>a(N),r(N);
	for(int i=0;i<N;i++)scanf("%d",&a[i]),r[i]=i;
	if(0<=a[0]&&a[0]<N){
		int i=0;
		for(;i<N;i++)if(a[0]!=a[i])break;
		if(i==N){
			puts("-1");
			return 0;
		}
	}
	uniform_int_distribution<int> distribution(0, N-1);
	for(;;){
		int x=distribution(engine);
		int y=distribution(engine);
		swap(r[x],r[y]);
		if(validate(a,r))break;
	}
	for(int i=0;i<N;i++)printf("%d\n",r[i]);
}