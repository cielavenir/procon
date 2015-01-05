#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
using namespace std;
const string T="JOI";
int main(){
	int H,W,Q;
	cin>>H>>W>>Q;
	vector<string>v(H);
	for(int i=0;i<H;i++)cin>>v[i];
	map<char,vector<vector<int> > >M;
	for(int c=0;c<T.size();c++){
		vector<vector<int> > &m=M[T[c]];
		m.resize(H+1);
		m[0].resize(W+1);
		for(int i=1;i<=H;i++){
			m[i].resize(W+1);
			for(int j=1;j<=W;j++)m[i][j]=m[i][j-1]+(v[i-1][j-1]==T[c]);
		}
		for(int j=1;j<=W;j++){
			for(int i=1;i<=H;i++)m[i][j]+=m[i-1][j];
		}
	}
	for(;Q--;){
		int a,b,x,y;
		cin>>a>>b>>x>>y;
		for(int c=0;c<T.size();c++){
			vector<vector<int> > &m=M[T[c]];
			printf(c<T.size()-1?"%d ":"%d\n",m[x][y]-m[a-1][y]-m[x][b-1]+m[a-1][b-1]);
		}
	}
}