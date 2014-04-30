#include <set>
#include <cstdio>
using namespace std;
int chain(int N){
	int n=N;
	set<int> se;
	se.insert(n);n=n*3+1;
	for(;se.find(n)==se.end();){
		se.insert(n);
		n=n%2?(n*3+1):(n/2);
	}
	return n==N;
}
int main(){
	int i=2,r=0;
	for(;i<=10000;i+=2)if(chain(i)){
		printf("%d\n",i);
		r++;
	}
	printf("%d\n",r); //34
}