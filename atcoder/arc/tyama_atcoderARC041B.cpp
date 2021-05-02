#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
	int N,M;
	cin>>N>>M;
	vector<string>v(N);
	for(int i=0;i<N;i++)cin>>v[i];
	vector<string>r=v;
	for(int i=0;i<N;i++)for(int j=0;j<M;j++){
		if(i==0||j==0||j==M-1)r[i][j]='0';
		else{
			int n=v[i-1][j]-'0';
			r[i][j]=n+'0';
			v[i-1][j]-=n,v[i][j-1]-=n,v[i][j+1]-=n;
			if(i<N-1)v[i+1][j]-=n;
		}
	}
	for(int i=0;i<N;i++)cout<<r[i]<<endl;
}