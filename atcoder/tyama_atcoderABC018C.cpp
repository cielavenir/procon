#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main(){
	int R,C,K;
	cin>>R>>C>>K;
	vector<string>v(R);
	vector<vector<int> >upper(R),lower(R);
	for(int i=0;i<R;i++){
		upper[i].resize(C);
		lower[i].resize(C);
		cin>>v[i];
	}
	for(int j=0;j<C;j++){
		int n=0;
		for(int i=0;i<R;i++){
			n=v[i][j]=='o'?n+1:0;
			upper[i][j]=n;
		}
		n=0;
		for(int i=R-1;i>=0;i--){
			n=v[i][j]=='o'?n+1:0;
			lower[i][j]=n;
		}
	}
	int r=0;
	for(int i=0;i<R;i++)for(int j=0;j<=C-(2*K-1);j++){
		int k=0;
		for(;k<2*K-1;k++)if(upper[i][j+k]<K-abs(K-1-k) || lower[i][j+k]<K-abs(K-1-k))break;
		r+=k==2*K-1;
	}
	printf("%d\n",r);
}