#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;
vector<int> T={5,7,5,7,7};
int solve(const vector<string>&v){
	for(int i=0;i<v.size();i++){
		for(int j=i,n=0,y=0;j<v.size();j++){
			n+=v[j].size();
			if(n==T[y]){
				if(++y==T.size())return i+1;
				n=0;
			}
		}
	}
	return -1;
}
int main(){
	int N;
	for(;cin>>N,N;){
		vector<string>v(N);
		for(int i=0;i<N;i++)cin>>v[i];
		printf("%d\n",solve(v));
	}
}