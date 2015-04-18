#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

vector<int>v(256);
const string target="yuki@";
int dfs(int d){
	if(d==target.size())return 0;
	char c=target[d];
	if(v[c]){v[c]--;if(dfs(d+1))return 1;v[c]++;}
	for(c++;c<='z';c++)if(v[c]){v[c]--;return 1;}
	return 0;
}

int main(){
	int R=0,c;
	for(;~(c=getchar());)v[c]++;
	for(;dfs(0);)R++;
	printf("%d\n",R);
}