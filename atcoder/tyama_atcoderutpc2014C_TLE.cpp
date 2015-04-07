#include <unordered_map>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;

unordered_map<int,vector<int> >h;
int N;

void dfs(int d,int cur,int prev,unordered_map<int,int>lst){
	//printf("%d\n",cur);
	if(lst.find(cur)!=lst.end()){
		int l=d-lst[cur];
		printf("%d %d\n",1+l/N,N-l%2);
		exit(0);
	}
	lst[cur]=d;
	for(auto &e:h[cur])if(e!=prev&&(lst.find(e)==lst.end()||lst[e]!=-1))dfs(d+1,e,cur,lst);
	lst[cur]=-1;
}
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		h[a].push_back(b);
		h[b].push_back(a);
	}
	unordered_map<int,int>lst;
	dfs(1,1,-1,lst);
}