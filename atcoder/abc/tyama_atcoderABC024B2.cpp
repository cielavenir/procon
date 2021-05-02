#include <vector>
#include <cstdio>
int main(){
	int N,T,r=0;
	scanf("%d%d",&N,&T);
	std::vector<int>v(N);
	for(int i=0;i<N;i++)scanf("%d",&v[i]);
	std::vector<int>t(v[N-1]+T+1);
	for(int i=0;i<N;i++)t[v[i]]++,t[v[i]+T]--;
	for(int i=0;i<t.size();i++)r+=(t[i]+=t[i-1])>0;
	printf("%d\n",r);
	return 0;
}