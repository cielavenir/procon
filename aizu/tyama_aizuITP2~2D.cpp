#include <list>
#include <vector>
#include <cstdio>
using namespace std;
int main(){
	int n,q,a,b,c;
	scanf("%d%d",&n,&q);
	vector<list<int>>v(n);
	for(;q--;){
		scanf("%d",&a);
		if(a==0)scanf("%d%d",&b,&c),v[b].push_back(c);
		if(a==1){scanf("%d",&b);int f=0;for(auto &e:v[b]){if(f)putchar(' ');f=1;printf("%d",e);}putchar('\n');}
		if(a==2)scanf("%d%d",&b,&c),v[c].splice(v[c].end(),v[b]);
	}
}
