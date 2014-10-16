#include <vector>
#include <cstdio>
using namespace std;

int joseph(int n,int diff,int initial){
	int r=0,i=1;
	for(;i<n;i++)r=(r+diff)%i;
	return (r+1+initial)%n+1;
}

int main(){
	int n,k,m;
	for(;scanf("%d%d%d",&n,&k,&m),n;printf("%d\n",joseph(n,k,m-1)));
}