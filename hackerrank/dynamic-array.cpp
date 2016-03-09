#include <vector>
#include <cstdio>
using namespace std;

int main(){
	int N,Q,last=0;
	scanf("%d%d",&N,&Q);
	vector<vector<int> >v(N);
	for(;Q--;){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(a==1)v[(b^last)%N].push_back(c);
		else printf("%d\n",last=v[(b^last)%N][c%v[(b^last)%N].size()]);
	}
}