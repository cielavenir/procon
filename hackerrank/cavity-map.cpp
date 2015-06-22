#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct{
	int x;
	int y;
}dir;
const vector<dir>D={
	{-1,0},
	{1,0},
	{0,-1},
	{0,1},
};
int main(){
	string line;
	int N,S=0;
	cin>>N;getline(cin,line);
	vector<string>v(N);
	for(int i=0;i<N;i++)getline(cin,v[i]);
	vector<string>w=v;
	for(int i=1;i<N-1;i++)for(int j=1;j<N-1;j++){
		//this lambda's dir can be auto in -std=c++1y.
		if(all_of(D.begin(),D.end(),[&](const dir &d){return v[i][j]>v[i+d.y][j+d.x];})){
			w[i][j]='X';
		}
	}
	for(int i=0;i<N;i++)cout<<w[i]<<endl;
}