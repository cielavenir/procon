#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long solve(const vector<vector<char>> &b){
	long long r=0;
	int h=b.size();
	int w=b[0].size();
	vector<vector<int>>c(h),d(h);
	for(int y=0;y<h;y++){
		c[y].resize(w);
		d[y].resize(w);
	}
	for(int y=h-1;y>=0;y--)for(int x=w-1;x>=0;x--){
		if(b[y][x]=='#'){
			c[y][x]=-1;
		}else{
			int q=x==w-1 ? -1 : c[y][x+1];
			c[y][x]=q+1;
		}
	}
	for(int x=w-1;x>=0;x--)for(int y=h-1;y>=0;y--){
		if(b[y][x]=='#'){
			d[y][x]=-1;
		}else{
			int q=y==h-1 ? -1 : d[y+1][x];
			d[y][x]=q+1;
		}
	}
	for(int y=h-1;y>=0;y--)for(int x=w-1;x>=0;x--){
		if(c[y][x]>0&&d[y][x]>0)r+=(long long)c[y][x]*d[y][x];
	}
	return r;
}

vector<vector<char>> transpose(const vector<vector<char>>&m){
	vector<vector<char>> r(m[0].size());
	for(int i=0;i<m[0].size();i++){
		r[i].resize(m.size());
		for(int j=0;j<m.size();j++)r[i][j]=m[j][i];
	}
	return r;
}

int main(){
	string s;
	int n,m;
	cin>>n>>m;getline(cin,s);
	vector<vector<char>>a(n);
	for(int i=0;i<n;i++){
		a[i].resize(m);
		for(int j=0;j<m;j++)cin>>a[i][j];
		getline(cin,s);
	}
	auto b=a;
	reverse(b.begin(),b.end());
	auto c=b;
	b=transpose(b);
	for(auto &e:c)reverse(e.begin(),e.end());
	auto d=transpose(a);
	reverse(d.begin(),d.end());
	cout<<solve(a)+solve(b)+solve(c)+solve(d)<<endl;
}

