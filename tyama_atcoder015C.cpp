#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#define M 300
using namespace std;
double m[M][M];
int main(){
	map<string,int>str2int;
	map<int,string>int2str;
	int n,nodes,i,j,k,l;
	string sl,ss;
	cin>>n;
	//nodes max value = n+1
	for(i=0;i<=n;i++)for(j=0;j<=n;j++)m[i][j]=-1;
	for(i=0;i<=n;i++)m[i][i]=1;
	for(nodes=i=0;i<n;i++){
		cin>>sl>>l>>ss;
		if(str2int.find(sl)==str2int.end()){
			str2int[sl]=nodes;
			int2str[nodes]=sl;
			nodes++;
		}
		if(str2int.find(ss)==str2int.end()){
			str2int[ss]=nodes;
			int2str[nodes]=ss;
			nodes++;
		}
		m[str2int[sl]][str2int[ss]]=l;
		m[str2int[ss]][str2int[sl]]=1.0/l;
	}
	for(k=0;k<nodes;k++)for(i=0;i<nodes;i++)for(j=0;j<nodes;j++){
		if(m[i][j]<0&&m[i][k]>0&&m[k][j]>0)m[i][j]=m[i][k]*m[k][j];
	}
	for(n=i=0;i<nodes;i++)for(j=0;j<nodes;j++){
		if(n<m[i][j])n=round(m[i][j]),k=i,l=j;
	}
	cout<<1<<int2str[k]<<"="<<n<<int2str[l]<<endl;
}
/*
3
a 5 b
c 2 b
c 4 d
=> 1a=10d
*/