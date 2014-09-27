//wget -O - https://projecteuler.net/project/resources/p082_matrix.txt
#include <iostream>
#include <string>
#include <queue>
#include <cstdlib>
using namespace std;
typedef pair<int,int> pii;
typedef struct{
	int x;
	int y;
}dir;
dir dirs[]={
	{1,0},
	{0,-1},
	{0,1},
};
#define MAX 80

vector<int> split_int(string &str, const char *delim){
	vector<int> result;
	int cutAt;
	while( (cutAt = str.find_first_of(delim)) != str.npos ){
		if(cutAt > 0){
			result.push_back(strtol(str.substr(0, cutAt).c_str(),NULL,10));
		}
		str = str.substr(cutAt + 1);
	}
	if(str.length() > 0){
		result.push_back(strtol(str.c_str(),NULL,10));
	}
	return result;
}

int D[MAX][MAX];
int main(){
	vector<vector<int> >M;
	{
		string line;
		for(;getline(cin,line);)M.push_back(split_int(line,","));
	}
	for(int y=0;y<MAX;y++)D[y][0]=M[y][0];
	for(int y=0;y<MAX;y++)for(int x=1;x<MAX;x++)D[y][x]=1<<29;
	queue<pii> q;
	for(int y=0;y<MAX;y++)q.push(make_pair(0,y));
	for(;!q.empty();){
		pii cur=q.front();q.pop();
		for(auto &d:dirs){
			int x=cur.first+d.x;
			int y=cur.second+d.y;
			if(0<=y&&y<MAX && D[y][x]>D[cur.second][cur.first]+M[y][x]){
				D[y][x]=D[cur.second][cur.first]+M[y][x];
				if(x<MAX-1)q.push(make_pair(x,y));
			}
		}
	}
	int ret=1<<29;
	for(int y=0;y<80;y++)if(ret>D[y][MAX-1])ret=D[y][MAX-1];
	cout<<ret<<endl;
}