#include <vector>
#include <bitset>
#include <iostream>
#include <algorithm>

#define coor(i,j) ((i)+(j)*m)
#define in(i,j) (0<=(i)&&(i)<m&&0<=(j)&&(j)<n)
using namespace std;
vector<bitset<626> > M(625);

main(){
	int m,n,d;
	int i,j,k;
	int success,ans;
	for(;cin>>m>>n>>d,d;cout<<ans<<endl){
		//create M
		for(j=0;j<n;j++)
			for(i=0;i<m;i++){
				M[coor(i,j)].reset();
				M[coor(i,j)][coor(i,j)]=1;
				cin>>k;M[coor(i,j)][m*n]=k;

				for(k=0;k<=d;k++){
					if(in(i-k,j-(d-k)))M[coor(i,j)][coor(i-k,j-(d-k))]=1;
					if(in(i+k,j-(d-k)))M[coor(i,j)][coor(i+k,j-(d-k))]=1;
					if(in(i-k,j+(d-k)))M[coor(i,j)][coor(i-k,j+(d-k))]=1;
					if(in(i+k,j+(d-k)))M[coor(i,j)][coor(i+k,j+(d-k))]=1;
				}
			}

		//solve
		k=0;
		for(i=0;i<m*n;i++){
			for(j=k;j<m*n&&!M[j][i];j++);
			if(j==m*n)continue;
			swap(M[k],M[j]);

			for(j=k+1;j<m*n;j++)if(M[j][i])M[j]^=M[k];
			k++;
		}

		//finalize
		ans=1;
		for(j=0;j<m*n;j++)if(M[j][m*n]&&M[j].count()==1)ans=0;
	}
}