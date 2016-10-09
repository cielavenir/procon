#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int N,T,x,y;
	scanf("%d%d",&N,&T);
	vector<int>v(T+1);
	for(;N--;){
		scanf("%d%d",&x,&y);
		v[x+1]++,v[y+1]--;
	}
	for(x=y=0;x<T;x++)y=max(y,v[x+1]+=v[x]);
	printf("%d\n",y);
}
