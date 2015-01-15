//言語の種類(ideoneの言語名で記載ください)：C++ 4.8.1
//あなたのコード
//総当りを行うには、stringをchar配列として扱える言語のほうが圧倒的有利な気がします。
//問題の縮退を行うとすれば、場合分けが面倒になってどこかで嵌りそうな気がしますし。
//最低限のチェックは入れましたが、extracase eで1分半要してしまうようです(TLE)。無念…。
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef struct{
	int x;
	int y;
}dir;
const dir D[]={
	{0,1},
	{1,0},
};
bool dfs(vector<string> &v,int x,int y){
	if(y==v.size())return true;
	if(x==v[0].size())return dfs(v,0,y+1);
	if(v[y][x]=='X')return dfs(v,x+1,y);
	v[y][x]='O';
	//for(auto &d:D){
	for(int i=0;i<2;i++){const dir &d=D[i];
		if(0<=x+d.x&&x+d.x<v[0].size() && 0<=y+d.y&&y+d.y<v.size() && v[y+d.y][x+d.x]=='O'){
			v[y+d.y][x+d.x]='X';
			bool r=dfs(v,x+1,y);
			v[y+d.y][x+d.x]='O';
			if(r)return true;
		}
	}
	return false;
}
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	vector<string>v;
	string line;
	int f[2]={0,0},lineno=0;
	for(;getline(cin,line);){
		if(line[line.size()-1]=='\r')line=line.substr(0,line.size()-1); //extracaseの改行コードがCRLFになってますよ！
		for(int i=0;i<line.size();i++)f[(lineno+i)%2]+=line[i]=='O';
		v.push_back(line);
		lineno++;
	}
	cout<<((f[0]+f[1]==0||f[0]!=f[1]||!dfs(v,0,0)) ? "no" : "yes")<<endl;
}