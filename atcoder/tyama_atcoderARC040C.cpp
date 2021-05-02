#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;
int main(){
	int N;
	cin>>N;
	vector<string>v(N);
	for(int i=0;i<N;i++)cin>>v[i];
	int r=0;
	for(int i=0;i<N;i++)for(int j=N-1;j>=0;j--)if(v[i][j]=='.'){
		for(int k=0;k<=j;k++)v[i][k]='o';
		if(i<N-1)for(int k=j;k<N;k++)v[i+1][k]='o';
		r++;
	}
	printf("%d\n",r);
}