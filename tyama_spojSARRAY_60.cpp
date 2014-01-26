#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct SAComp{
	const int h,*g;
	SAComp(const int h, const int* g) : h(h), g(g) {}
	bool operator()(const int a, const int b){
		return a == b ? false : g[a] != g[b] ? g[a] < g[b] : g[a+h] < g[b+h];
	}
};

char t[100010];
int main(){
	scanf("%s",t);
	int n=strlen(t)+1; //include last \0
	int g[n],b[n];
	int suff[n];
	for(int i=0;i<n;i++)suff[i]=i,g[i]=t[i];
	b[0]=b[n-1]=0;
	sort(suff,suff+n,SAComp(0,g));
	for(int h=1;b[n-1]!=n-1;h<<=1){
		SAComp comp(h,g);
		sort(suff,suff+n,comp);
		for(int i=0;i<n-1;i++)b[i+1]=b[i]+comp(suff[i],suff[i+1]);
		for(int i=0;i<n;i++)g[suff[i]]=b[i];
	}
	for(int i=1;i<n;i++)printf("%d\n",suff[i]);
}