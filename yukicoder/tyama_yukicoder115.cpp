#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;
void dfs(vector<int>&v,int s,int t,int i,int n,int d,int k){
	if(d==k-1){
		int x=t-s;
		if(i<=x&&x<=n){
			for(int j=0;j<v.size();j++)printf("%d ",v[j]);
			printf("%d\n",x);
			exit(0);
		}
	}else{
		int z=(k-(d+1))*(2*(n-k+(d+1)+1)+(k-(d+1)-1))/2;
		for(;i<=n;i++){
			//t<=s+i+((n-k+(d+1)+1)〜nの和) && (s+(i〜(i+k-d-1)の和)<=t
			if(t<=s+i+z && s+(k-d)*(2*i+(k-d-1))/2<=t){
				v.push_back(i);
				dfs(v,s+i,t,i+1,n,d+1,k);
				v.pop_back();
			}
		}
	}
}
int main(){
	int n,d,k;
	scanf("%d%d%d",&n,&d,&k);
	vector<int>v;
	dfs(v,0,d,1,n,0,k);
	puts("-1");
}