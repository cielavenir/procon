//http://nabetani.sakura.ne.jp/hena/orde27ligmir/
//https://qiita.com/Nabetani/items/0b2f459ec128c89948f4

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cstdio>
using namespace std;

//x,y
map<
	char,map<
		pair<int,int>,pair<int,int>
	>
>D={
	{'.',{
		{{0,-1},{0,-1}},  //N
		{{1,0},{1,0}},   //E
		{{0,1},{0,1}},   //S
		{{-1,0},{-1,0}}, //W
	}},
	{'1',{
		{{0,-1},{1,0}},  
		{{1,0},{0,-1}},
		{{0,1},{-1,0}},
		{{-1,0},{0,1}},
	}},
	{'0',{
		{{0,-1},{-1,0}},  
		{{1,0},{0,1}},
		{{0,1},{1,0}},
		{{-1,0},{0,-1}},
	}},
};
const int H=5,W=5;

vector<string> split(string &str, const char *delim){
	vector<string> result;
	int cutAt;
	while( (cutAt = str.find_first_of(delim)) != str.npos ){
		if(cutAt > 0){
			result.push_back(str.substr(0, cutAt));
		}
		str = str.substr(cutAt + 1);
	}
	if(str.length() > 0){
		result.push_back(str);
	}
	return result;
}

int main(){
	string line;
	for(;getline(cin,line);){
		vector<string>m=split(line,"/");
		int x=0,y=0;
		for(int h=0;h<H;h++)for(int w=0;w<W;w++){
			if(m[h][w]=='Y'){
				x=w,y=h;
				m[h][w]='.';
			}
		}
		set<char>r;
		int dx=0,dy=-1;
		set<vector<int>>visited={{x,y,dx,dy}};
		for(;0<=x&&x<W && 0<=y&&y<H && m[y][x]!='x';){
			r.insert(x+y*W+97);
			int ndx,ndy;
			tie(ndx,ndy)=D[m[y][x]][{dx,dy}];
			dx=ndx,dy=ndy;
			x+=dx;
			y+=dy;
			vector<int>k={x,y,dx,dy};
			if(visited.find(k)!=visited.end())break;
			visited.insert(k);
		}
		for(auto &e:r)putchar(e);
		puts("");
		fflush(stdout);
	}
}
