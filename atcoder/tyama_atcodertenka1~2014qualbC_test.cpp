#include <iostream>
#include <string>
#include <vector>
#define MD 4
using namespace std;
int D[MD][2]={
	{-1,0},
	{1,0},
	{0,-1},
	{0,1},
};
int main(){
	string line;
	vector<string> before;
	vector<string> after;
	for(;cin>>line;){
		before.push_back(line);
		after.push_back(string(line.size(),'.'));
	}
	int n=before[0].size();
	for(int j=0;j<n*n;j++){
		int black=0;
		for(int d=0;d<MD;d++)if(0<=j/n+D[d][0]&&j/n+D[d][0]<n && 0<=j%n+D[d][1]&&j%n+D[d][1]<n && before[j/n+D[d][0]][j%n+D[d][1]]=='#')black++;
		after[j/n][j%n]=(black&1) ? '#':'.';
	}
	for(int i=0;i<n;i++)cout<<after[i]<<endl;
}