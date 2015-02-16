#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
using namespace std;
#define coor(y,x) ((y)*siz+(x))

int main(){
	//パス中に【位置を問わず】同じ文字が2つ以上あってはならない
	//DAGに帰着できない
	map<int,int>g_siz={{1,1},{4,2},{9,3},{16,4},{25,5},{36,6}};
	string line;
	for(;getline(cin,line);){
/*
		int len=line.size();
		int siz=g_siz[len];
		vector<vector<int> >v(len);
		for(int y=0;y<len;y++){
			v[y].resize(len);
			for(int x=0;x<len;x++)v[y][x]=1<<29;
			v[y][y]=0;
		}
		for(int y=0;y<siz;y++){
			for(int x=0;x<siz;x++){
				if(x<siz-1 && line[coor(y,x)]!=line[coor(y,x+1)]){
					v[coor(y,x)][coor(y,x+1)]=v[coor(y,x+1)][coor(y,x)]=-1;
				}
				if(y<siz-1 && line[coor(y,x)]!=line[coor(y+1,x)]){
					v[coor(y,x)][coor(y+1,x)]=v[coor(y+1,x)][coor(y,x)]=-1;
				}
			}
		}
		for(auto &e:v)cout<<e<<endl;
		for(int k=0;k<len;k++)for(int i=0;i<len;i++)for(int j=0;j<len;j++){
			if(v[i][j]<1<<29 && v[i][j]>v[i][k]+v[k][j])v[i][j]=v[i][k]+v[k][j];
		}
		for(auto &e:v)cout<<e<<endl;
		int r=0;
		for(int y=0;y<len;y++){
			for(int x=0;x<len;x++)if(r>v[y][x])r=v[y][x];
		}
*/
		//printf("%d\n",-r);
		printf("%d\n",line.size()/2+line.size()/4);
	}
}