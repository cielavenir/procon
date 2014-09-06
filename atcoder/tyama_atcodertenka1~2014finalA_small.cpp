#include <unordered_map>
#include <cstdio>
int h,n,w;
std::unordered_map<int,int>m;
int dfs(int d){
	if(d==w)return 1;
	int ret=0;
	for(int i=d<1;i<h;i++){
		if(m[i]<n){
			m[i]++;
			ret=(ret+dfs(d+1))%1000000007;
			m[i]--;
		}
	}
	return ret;
}

int main(){
	scanf("%d%d%d",&h,&n,&w);
	if(w>4)return 1;
	printf("%d\n",dfs(0));
}