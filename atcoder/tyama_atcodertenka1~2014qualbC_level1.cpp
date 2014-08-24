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
	int n;
	cin>>n;
	if(n>4)return 1;
	vector<string> result(n);
	vector<string> before(n);
	vector<string> after(n);
	for(int i=0;i<n;i++){
		cin>>result[i];
		before[i]=after[i]=result[i]; //alloc
	}
	for(int i=0;i<1<<(n*n);i++){
		for(int j=0;j<n*n;j++)before[j/n][j%n]=( i&(1<<j) )?'#':'.';
		for(int j=0;j<n*n;j++){
			int black=0;
			for(int d=0;d<MD;d++)if(0<=j/n+D[d][0]&&j/n+D[d][0]<n && 0<=j%n+D[d][1]&&j%n+D[d][1]<n && before[j/n+D[d][0]][j%n+D[d][1]]=='#')black++;
			after[j/n][j%n]=(black&1) ? '#':'.';
		}
		if(after==result)break;
	}
	for(int i=0;i<n;i++)cout<<before[i]<<endl;
}