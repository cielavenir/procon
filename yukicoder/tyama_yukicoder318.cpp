#include <vector>
#include <map>
#include <cstdio>
int main(){
	int N,x,i=0;scanf("%d",&N);
	std::map<int,int>m,s;
	std::vector<int>v(N),sa(N),sb(N);
	for(;i<N;sb[i]++,m[x]=i++){
		scanf("%d",&x);
		v[i]=x;
		if(m.find(x)==m.end())sa[i]++;else sb[m[x]]--;
	}
	for(i=-1;++i<N;){
		if(sa[i])s[v[i]]=1;
		printf(i<N-1?"%d ":"%d\n",s.rbegin()->first);
		if(sb[i])s.erase(v[i]);
	}
}