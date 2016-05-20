#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int N,P,X;
	for(;~scanf("%d%d",&N,&P);){
		vector<int>v;
		for(int i=0;i<N;i++){
			int t;
			if(i==P)scanf("%d",&X);
			else scanf("%d",&t),v.push_back(t);
		}
		if(X>300)puts("0 0");
		else{
			int n=0,t=X,p=X;
			sort(v.begin(),v.end());
			v.push_back(999); //sentinel
			for(;t+v[n]<=300;n++)t+=v[n],p+=t;
			printf("%d %d\n",n+1,p);
		}
	}
}