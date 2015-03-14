#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;

vector<int>table(99);

int dfs(int prev,int d,int N,set<int> &s){
	if(d==N)return !table[prev+1];
	int r=0;
	for(int i=2;i<=N;i++)if(!table[prev+i]&&s.find(i)==s.end()){
		s.insert(i);
		r+=dfs(i,d+1,N,s);
		s.erase(i);
	}
	return r;
}

int main(){
	table[0]=table[1]=1;
	for(int i=2;i<99;i++)if(!table[i])for(int j=i+i;j<99;j+=i)table[j]=1;

	set<int>s;
	int r=0;
	int N=18;
	printf("%d\n",dfs(1,1,N,s));
}