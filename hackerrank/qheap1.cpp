#include <set>
#include <cstdio>
using namespace std;

int main(){
	multiset<int> se;
	int Q,C,N;
	scanf("%d",&Q);
	for(;Q--;){
		scanf("%d",&C);
		if(C==3)printf("%d\n",*se.begin());
		else{
			scanf("%d",&N);
			if(C==1)se.insert(N);
			else se.erase(se.find(N));
		}
	}
}