//http://qiita.com/Nabetani/items/c516875b13a4d282affe
//http://nabetani.sakura.ne.jp/hena/orde05dokitruck/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<int,map<int,vector<int>>>T={
	{1,{{0,{0,1}},{1,{1,2}},{2,{2}}}},
	{2,{{0,{0,2}},{1,{1}},{2,{1,2}}}},
	{3,{{0,{0,2}},{1,{0,1}},{2,{2}}}},
	{4,{{0,{0}},{1,{0,1}},{2,{1,2}}}},
	{5,{{0,{0}},{1,{1,2}},{2,{0,2}}}},
	{6,{{0,{0,1}},{1,{1}},{2,{0,2}}}},
	{7,{{0,{0}},{1,{}},{2,{2}}}},
	{8,{{0,{}},{1,{1}},{2,{2}}}},
	{9,{{0,{0}},{1,{1}},{2,{}}}},
};

string line;
map<pair<int,int>,bool>m;

int dfs(int d,int cur){
	if(d==line.size())return true;
	if(m.find({d,cur})!=m.end())return m[{d,cur}];
	return m[{d,cur}]=any_of(
		T[line[d]-'0'][cur].begin(),
		T[line[d]-'0'][cur].end(),
		[&](int e){return dfs(d+1,e);}
	);
}

int main(){
	for(;getline(cin,line);){
		m.clear();
		string r;
		for(int i=0;i<3;i++)if(dfs(0,i))r+=i+'a'; // charキャスト不要でした
		cout<<(r.empty()?"-":r)<<endl;
	}
}