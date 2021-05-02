#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long val_t;
const int H=3,W=3;

vector<int>m;
int B[H*W],C[H*W];
int calc(){
	int x=0,y=0;
	for(int h=0;h<H-1;h++)for(int w=0;w<W;w++)(m[(h+1)*W+w]==m[h*W+w]?x:y)+=B[h*W+w];
	for(int h=0;h<H;h++)for(int w=0;w<W-1;w++)(m[h*W+w+1]==m[h*W+w]?x:y)+=C[h*W+w];
	return x; //discard y.
}
map<vector<int>,int>memo;
int dfs(int d){
	if(memo.find(m)!=memo.end())return memo[m];
	if(d==H*W)return memo[m]=calc();
	vector<int>v;
	for(int i=0;i<H*W;i++)if(!m[i]){
		m[i]=d%2?'x':'o';
		v.push_back(dfs(d+1));
		m[i]=0;
	}
	return memo[m]=d%2 ? *min_element(v.begin(),v.end()) : *max_element(v.begin(),v.end());
}
int main(){
	scanf("%d%d%d%d%d%d",B+0,B+1,B+2,B+3,B+4,B+5);
	scanf("%d%d%d%d%d%d",C+0,C+1,C+3,C+4,C+6,C+7);
	int total=0;
	for(int i=0;i<H*W;i++)total+=B[i]+C[i];
	m.resize(H*W);
	int r=dfs(0);
	printf("%d\n%d\n",r,total-r);
}