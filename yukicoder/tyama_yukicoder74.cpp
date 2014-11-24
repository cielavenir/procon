#include <vector>
#include <bitset>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n,d,w;
	int i,j;
	cin>>n;
	vector<bitset<101> > M(100);
	for(i=0;i<n;i++){
		cin>>d;
		M[(i+d)%n][i]=1;
		M[((i-d)%n+n)%n][i]=1;
	}
	for(i=0;i<n;i++){
		cin>>w;
		M[i][n]=w^1;
	}
	int k=0;
	for(i=0;i<n;i++){
		for(j=k;j<n&&!M[j][i];j++);
		if(j==n)continue;
		swap(M[k],M[j]);
		for(j=k+1;j<=n;j++)if(M[j][i])M[j]^=M[k];
		k++;
	}
	int ans=1;
	for(j=k;j<n;j++)if(M[j][n])ans=0;
	cout<<(ans?"Yes":"No")<<endl;
}