#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

void dfs(const vector<string> &v,vector<int> &f,int d){
	if(d==v.size()){
		for(int j=0;j<d;j++){
			cout<<v[j].substr(0,f[j])<<' '<<v[j].substr(f[j])<<endl;
		}
		exit(0);
	}
	for(int i=1;i<=2;i++){
		int j=0;
		for(;j<d;j++){
			if(i==1){
				if(
					(v[d].substr(0,1)==(f[j]==1?v[j].substr(0,1):v[j].substr(2))) ||
					(v[d].substr(1)==(f[j]==1?v[j].substr(1):v[j].substr(0,2)))
				)break;
			}
			if(i==2){
				if(
					(v[d].substr(2)==(f[j]==1?v[j].substr(0,1):v[j].substr(2))) ||
					(v[d].substr(0,2)==(f[j]==1?v[j].substr(1):v[j].substr(0,2)))
				)break;
			}
		}
		if(j==d){
			f.push_back(i);
			dfs(v,f,d+1);
			f.pop_back();
		}
	}
}
int main(){
	int N;
	cin>>N;
	if(N>52*52){
		cout<<"Impossible"<<endl;
		return 0;
	}
	vector<string>v(N);
	for(int i=0;i<N;i++)cin>>v[i];
	vector<int>f;
	dfs(v,f,0);
	cout<<"Impossible"<<endl;
}
