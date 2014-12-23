//fails against some cases? bah
#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <tuple>
#include <cstdlib>
using namespace std;
typedef tuple<int,int,int> tiii;
typedef struct{
	int x;
	int y;
	int z;
}dir;
dir D[]={
	{-1,0,0},
	{1,0,0},
	{0,-1,0},
	{0,1,0},
	{0,0,-1},
	{0,0,1},
};

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
		vector<string> a=split(line,";");
		int n=strtol(a[0].c_str(),NULL,10);
		vector<vector<vector<char>>>v(n);
		int idx=0;
		for(int z=0;z<n;z++){
			v[z].resize(n);
			for(int y=0;y<n;y++){
				v[z][y].resize(n);
				for(int x=0;x<n;x++){
					v[z][y][x]=a[1][idx++];
				}
			}
		}
		tiii start,goal;
		for(int x=0;x<n;x++){
			if(v[0][0][x]==' ')start=make_tuple(x,0,0);
			if(v[0][n-1][x]==' ')start=make_tuple(x,n-1,0);
		}
		for(int y=0;y<n;y++){
			if(v[0][y][0]==' ')start=make_tuple(0,y,0);
			if(v[0][y][n-1]==' ')start=make_tuple(n-1,y,0);
		}
		for(int x=0;x<n;x++){
			if(v[n-1][0][x]==' ')goal=make_tuple(x,0,n-1);
			if(v[n-1][n-1][x]==' ')goal=make_tuple(x,n-1,n-1);
		}
		for(int y=0;y<n;y++){
			if(v[n-1][y][0]==' ')goal=make_tuple(0,y,n-1);
			if(v[n-1][y][n-1]==' ')goal=make_tuple(n-1,y,n-1);
		}
		map<tiii,int>depth;
		queue<tiii>q;
		depth[start]=1;
		q.push(start);
		for(;!q.empty();){
			tiii cur=q.front();q.pop();
			bool end=false;
			for(auto &d:D){
				tiii nxt=make_tuple(get<0>(cur)+d.x,get<1>(cur)+d.y,get<2>(cur)+d.z);
				if(get<0>(nxt)<0||n<=get<0>(nxt) || get<1>(nxt)<0||n<=get<1>(nxt) || get<2>(nxt)<0||n<=get<2>(nxt))continue;
				if(
					d.z==-1 ? (get<2>(cur)>0&&v[get<2>(cur)][get<1>(cur)][get<0>(cur)]=='o'&&v[get<2>(cur)-1][get<1>(cur)][get<0>(cur)]==' ') :
					d.z==1 ? (get<2>(cur)<n-1&&v[get<2>(cur)][get<1>(cur)][get<0>(cur)]==' '&&v[get<2>(cur)+1][get<1>(cur)][get<0>(cur)]=='o') :
					v[get<2>(nxt)][get<1>(nxt)][get<0>(nxt)]==' '
				){
					if(depth.find(nxt)==depth.end()){
						depth[nxt]=depth[cur]+1;
						q.push(nxt);
						if(nxt==goal)end=true;
					}
				}
			}
			if(end)break;
		}
		printf("%d\n",depth[goal]);
	}
}