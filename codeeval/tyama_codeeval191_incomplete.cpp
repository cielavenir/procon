#include <vector>
#include <bitset>
#include <iostream>
#include <algorithm>
#define coor(i,j) ((i)+(j)*m)
#define in(i,j) (0<=(i)&&(i)<m&&0<=(j)&&(j)<n)
using namespace std;
vector<bitset<101> > M(100);

int main(){
	int m,n,d=1;
	string s;
	int i,j,k,ans;
	for(;cin>>n>>m>>s;cout<<ans<<endl){
		//create M
		for(j=0;j<n;j++){
			for(i=0;i<m;i++){
				M[coor(i,j)].reset();
			}
		}
		for(j=0;j<n;j++){
			for(i=0;i<m;i++){
				M[coor(i,j)][coor(i,j)]=1;
				M[coor(i,j)][m*n]=s[j*(m+1)+i]=='O';
				for(k=0;k<=d;k++){
					if(in(i-k,j-(d-k)))M[coor(i-k,j-(d-k))][coor(i,j)]=1;
					if(in(i+k,j-(d-k)))M[coor(i+k,j-(d-k))][coor(i,j)]=1;
					if(in(i-k,j+(d-k)))M[coor(i-k,j+(d-k))][coor(i,j)]=1;
					if(in(i+k,j+(d-k)))M[coor(i+k,j+(d-k))][coor(i,j)]=1;
				}
			}
		}

		//solve
		ans=k=0;
		for(i=0;i<m*n;i++){
			for(j=k;j<m*n&&!M[j][i];j++);
			if(j==m*n)continue;
			swap(M[k],M[j]);
			for(j=k+1;j<m*n;j++)if(M[j][i])M[j]^=M[k];
			ans+=M[k][m*n]; //broken
			k++;
		}

		//finalize
		for(j=k;j<m*n;j++)if(M[j][m*n])ans=-1;
	}
}