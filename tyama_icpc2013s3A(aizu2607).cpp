#include <vector>
#include <cstdio>
using namespace std;
int main(){
	int n,d,x;
	scanf("%d%d%d",&n,&d,&x);
	vector<vector<int> >p(d);
	for(int i=0;i<d;i++){
		p[i].resize(n);
		for(int j=0;j<n;j++)scanf("%d",&p[i][j]);
	}
	for(int i=0;i<d-1;i++){
		int ret=x+1;
		vector<int>bag(x+1);
		bag[0]=1;
		for(int j=0;j<n;j++)for(int k=p[i][j];k<=x;k++){
			if(bag[k-p[i][j]]>=1&&bag[k]<bag[k-p[i][j]]+p[i+1][j]){
				bag[k]=bag[k-p[i][j]]+p[i+1][j];
				if(ret<bag[k]+x-k)ret=bag[k]+x-k;
			}
		}
		x=ret-1;
	}
	printf("%d\n",x);
}