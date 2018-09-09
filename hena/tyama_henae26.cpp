// https://cedretaber.github.io/doukaku/e26/
// https://qiita.com/Nabetani/items/0bcabb80bdcbc9b2ff52

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <valarray>
#include <algorithm>
#define coor(i,j) ((i)+(j)*m)
#define in(i,j) (0<=(i)&&(i)<m&&0<=(j)&&(j)<n)
using namespace std;

int main(){
	int t=0,T,m,n,d=2;
	int i,j,k;
	int success,ans;
	for(cin>>T;t<T;t++){
		if(t)puts("");
		printf("%d\n",t);
		cin>>m;n=m;
		vector<valarray<int>> M;
		for(int i=0;i<m*n;i++)M.push_back(valarray<int>(m*n*2));
		for(j=0;j<n;j++){
			for(i=0;i<m;i++){
				M[coor(i,j)][coor(i,j)]=1;
				M[coor(i,j)][m*n+i+j*m]=1;
				if(in(i-1,j))M[coor(i-1,j)][coor(i,j)]=3;
				if(in(i+1,j))M[coor(i+1,j)][coor(i,j)]=3;
				if(in(i,j-1))M[coor(i,j-1)][coor(i,j)]=3;
				if(in(i,j+1))M[coor(i,j+1)][coor(i,j)]=3;
			}
		}

		//solve
		k=0;
		for(i=0;i<m*n;i++){
			for(j=k;j<m*n&&M[j][i]%2==0;j++);
			if(j!=m*n){
				swap(M[k],M[j]);
				if(M[k][i]==3)M[k]*=3,M[k]%=4;
			}else{
				for(j=k;j<m*n&&M[j][i]%4!=2;j++);
				if(j==m*n)continue; /// todo
				swap(M[k],M[j]);
			}
			for(j=0;j<m*n;j++)if(j!=k&&M[j][i]){
				if(M[j][i]==2)M[j]-=(M[k][i]==2?1:2)*M[k],M[j]+=8,M[j]%=4;
				else if(M[j][i]==M[k][i])M[j]-=M[k],M[j]+=4,M[j]%=4;
				else M[j]-=3*M[k],M[j]+=12,M[j]%=4;
			}
			k++;
		}
		//for(int i=0;i<m*n;i++)for(int j=0;j<m*n*2;j++)printf(j<m*n*2-1?"%d ":"%d\n",M[i][j]);
		map<string,int>ma;
		for(i=0;i<k;i++){
			int q;cin>>q;q=(5-q)%4;
			int g=0;
			for(j=0;j<i;j++)g+=M[j][i];
			g%=4;
			if((q-g)%M[i][i]){return -1;}
			int f=(q-g+4)%4/M[i][i];
			M[i]*=f,M[i]%=4;
			if(g==q)continue;
			for(j=m*n;j<m*n*2;j++){
				for(int k=0;k<M[i][j]%4;k++)ma[to_string((j-m*n)%m+1)+" "+to_string((j-m*n)/m+1)]++;
			}
		}
		for(;i<m*n;i++){
			cin>>k;
			// k...m*n: quiet patterns; implement searching shortest answer
		}
		for(auto &e:ma){
			for(i=0;i<e.second%4;i++)cout<<e.first<<endl;
		}
	}
}
