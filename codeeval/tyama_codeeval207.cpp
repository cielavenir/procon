#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

typedef struct{
	int x;
	int y;
}dir;
const dir D[]={
	{-1,0},
	{0,-1},
	{0,1},
	{1,0},
};

int main(){
	string line;
	for(;getline(cin,line);){
		//input
		vector<string>v;
		istringstream ss(line);
		string s;
		do{
			ss>>s;
			v.push_back(s);
		}while(ss>>s);

		//prepare warshall-floyd
		int H=v.size(),W=v[0].size();
		vector<int>F,G;
		vector<vector<int> >dist(H*W);
		for(int i=0;i<H*W;i++){
			dist[i].resize(H*W);
			for(int j=0;j<H*W;j++)dist[i][j]=(i!=j)<<29;
		}
		for(int h=0;h<H;h++)for(int w=0;w<W;w++){
			if(v[h][w]=='^')continue;
			int coor=h*W+w;
			if(v[h][w]=='S'||v[h][w]=='F')F.push_back(coor);
			if(v[h][w]=='P')G.push_back(coor);
			for(auto d:D){
				int h1=h+d.y;
				int w1=w+d.x;
				if(0<=h1&&h1<H && 0<=w1&&w1<W && v[h1][w1]!='^'){
					int coor1=h1*W+w1;
					dist[coor][coor1]=1;
				}
			}
		}

		//warshall-floyd
		for(int k=0;k<H*W;k++)for(int i=0;i<H*W;i++)for(int j=0;j<H*W;j++){
			dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
		}
		printf("%d\n",min(dist[F[0]][F[1]]*2,min(
			dist[F[0]][G[0]]*2+1+dist[G[0]][G[1]]+1+dist[G[1]][F[1]]*2,
			dist[F[0]][G[1]]*2+1+dist[G[1]][G[0]]+1+dist[G[0]][F[1]]*2
		)));
	}
}