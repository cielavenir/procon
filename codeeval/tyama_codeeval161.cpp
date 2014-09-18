#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef struct{
	int x;
	int y;
}dir;
const dir D[]={
	{-1,-1},
	{-1,0},
	{-1,1},
	{0,-1},
	{0,1},
	{1,-1},
	{1,0},
	{1,1},
};
int main(){
	vector<string>v;
	string line;
	for(;getline(cin,line);)v.push_back(line);
	int h=v.size(),w=v[0].size();
	for(int i=0;i<10;i++){
		vector<string>_w=v; //alloc
		for(int y=0;y<h;y++){
			for(int x=0;x<w;x++){
				int l=0;
				for(auto d:D){
					if(0<=y+d.y&&y+d.y<h && 0<=x+d.x&&x+d.x<w && v[y+d.y][x+d.x]=='*')l++;
				}
				_w[y][x]=(l==3||(l==2&&v[y][x]=='*')) ? '*' : '.';
			}
		}
		v=_w;
	}
	for(int y=0;y<h;y++)cout<<v[y]<<endl;
}