#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

int main(){
	int n,m,d,r=0;
	cin>>n>>m>>d;
	vector<string>v(n);
	for(int i=0;i<n;i++)cin>>v[i];
	for(int i=0;i<n;i++)for(int j=0;j<m;j++){
		if(i+d<=n){
			int e=0;
			for(;e<d;e++)if(v[i+e][j]=='#')break;
			if(e==d)r++;
		}
		if(j+d<=m){
			int e=0;
			for(;e<d;e++)if(v[i][j+e]=='#')break;
			if(e==d)r++;
		}
	}
	printf("%d\n",r);
	return 0;
}
