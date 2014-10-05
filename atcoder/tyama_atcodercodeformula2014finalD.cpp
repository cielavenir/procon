#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
	//input
	int n;
	scanf("%d",&n);
	vector<int>h(n);
	for(int i=0;i<n;i++)scanf("%d",&h[i]);
	//first.first=開始時間
	//first.second=終了時間
	//second=映画の種類
	vector<pair<pair<int,int>,int> >m(n);
	for(int z,s,e,i=0;i<n;i++){
		scanf("%d%d%d",&z,&s,&e);
		m[i].first.first=s;
		m[i].first.second=e;
		m[i].second=z;
	}
	sort(m.begin(),m.end());
	//solve
	vector<vector<int> >M(n);
	for(int i=0;i<n;i++)M[i].resize(n);
	for(int i=0;i<n;i++){
		M[i][0]=h[0];
		for(int j=1;j<n;j++)M[i][j]=-1;
	}
	for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)if(m[j].first.first>=m[i].first.second){
		int dupl;
		if(m[i].second==m[j].second){
			for(dupl=1;M[i][dupl-1]>=0;dupl++){
				if(M[j][dupl]<M[i][dupl-1]+h[dupl]){
					M[j][dupl]=M[i][dupl-1]+h[dupl];
				}
			}
		}else{
			for(dupl=0;M[i][dupl]>=0;dupl++){
				if(M[j][0]<M[i][dupl]+h[0]){
					M[j][0]=M[i][dupl]+h[0];
				}
			}
		}
	}
	int r=0;
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(r<M[i][j])r=M[i][j];
	printf("%d\n",r);

/*
	vector<int>duplicate(n);
	vector<int>M(n);
	for(int i=0;i<n;i++)M[i]=h[0],duplicate[i]=0;
	for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)if(m[j].first.first>=m[i].first.second){
		int dupl=duplicate[i];
		if(m[i].second==m[j].second){
			dupl++;
		}else{
			dupl=0;
		}
		if(M[j]<M[i]+h[dupl]){
			duplicate[j]=dupl;
			M[j]=M[i]+h[dupl];
		}
	}
	int r=0;
	for(int i=0;i<n;i++)if(r<M[i])r=M[i];
	printf("%d\n",r);
*/
}