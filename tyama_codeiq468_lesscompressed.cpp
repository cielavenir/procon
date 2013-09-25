#include <vector>
#include <cstdio>
using namespace std;
vector<int> a;
void dfs(int d,int width){
	int i,j;
	if(d<5){
		for(i=0;i<=width;i++){
			a.push_back(i);
			dfs(d+1,width);
			a.pop_back();
		}
			a.push_back(i); //width+1
			dfs(d+1,width+1);
			a.pop_back();
	}else{
		vector<vector<int> >blk(width+1);
		for(i=0;i<a.size();i++)blk[a[i]].push_back(i+1); //a[i]はインデックスiが入る箱の番号を表す
		for(i=0;i<blk.size();i++){
			for(j=0;j<blk[i].size();j++)printf("%d",blk[i][j]);
			putchar(i==blk.size()-1 ? '\n' : '.');
		}
	}
}
main(){a.push_back(0);dfs(1,0);}