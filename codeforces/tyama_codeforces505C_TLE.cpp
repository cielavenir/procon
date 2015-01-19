#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
typedef int pii;
unordered_map<pii,int>memo;
const int M=30000;
int z[M*2+2];
int z1[M*2+2];
int D;

int dfs(int cur,int l){
	int ret=0;
	if(cur>M)return 0;
	pii p=(cur<<16)|l; //make_pair(cur,l);
	if(memo.find(p)!=memo.end())return memo[p];
	if(l<=2){
		//for(int i=cur+1;i<=M;i++)ret+=z[i];
		ret=z1[cur+1];
	}else{
		for(int i=-1;i<=1;i++){
			if(0<l+i && l+i<=D*2){ //fixme
				ret=max(ret,dfs(cur+l+i,l+i));
			}
		}
	}
	return memo[p]=ret+z[cur];
}
			
int main(){
	int N;
	cin>>N>>D;
	for(int i=0;i<N;i++){
		int x;
		cin>>x;
		z[x]++;
	}
	for(int i=M-1;i>=0;i--)z1[i]=z[i]+z[i+1];
	cout<<dfs(D,D)<<endl;
}