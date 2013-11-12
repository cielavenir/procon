#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
void output(int i,int j){
	cout<<i<<' '<<j<<endl;
	exit(0);
}
int main(){
	int y,x,k,i,j;
	cin>>y>>x>>k;
	string s;
	vector<string> grid;
	for(i=0;i<y;i++){
		cin>>s;
		grid.push_back(s);
	}

	//logic
	for(i=y-1;i>=0;i--){
		for(int j=0;j<x;j++){
			if(grid[i][j]=='-')continue;
			if(j<x-1&&grid[i][j+1]==grid[i][j])output(i,j);
			if(i>0&&grid[i-1][j]==grid[i][j])output(i,j);
		}
	}
	return 1;
}