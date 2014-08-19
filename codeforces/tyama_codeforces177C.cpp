#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
map<int, vector<int> >like;
map<int, vector<int> >dislike;
vector<int> memo_all;
vector<int> memo;

int dfs(int &n){
	int r=1,s;
	vector<int>v=like[n];
	for(int i=0;i<v.size();i++){
		if(find(memo_all.begin(),memo_all.end(),v[i])==memo_all.end()){
			memo.push_back(v[i]);
			memo_all.push_back(v[i]);
			s=dfs(v[i]);
			if(!s)return 0;
			r+=s;
		}
	}
	return r;
}

main(){
	int n,k,x,y;

	for(scanf("%d%d",&n,&k);k;k--){
		scanf("%d%d",&x,&y);
		like[x].push_back(y);
		like[y].push_back(x);
	}
	for(scanf("%d",&k);k;k--){
		scanf("%d%d",&x,&y);
		dislike[x].push_back(y);
		dislike[y].push_back(x);
	}
	for(x=0,y=1;y<=n;y++){
		if(find(memo_all.begin(),memo_all.end(),y)==memo_all.end()){
			memo.clear();
			memo.push_back(y);
			memo_all.push_back(y);
			k=dfs(y);
			for(int i=0;i<memo.size()-1;i++)
				for(int j=i+1;j<memo.size();j++){
					if(find(dislike[memo[i]].begin(),dislike[memo[i]].end(),memo[j])!=dislike[memo[i]].end())goto next;
				}
			if(x<k)x=k;
		}
		next:;
	}
	printf("%d\n",x);
}