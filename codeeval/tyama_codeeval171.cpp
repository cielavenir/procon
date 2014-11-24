#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <climits>
using namespace std;
//typedef vector<int> vi;
short M[500][500],X[500][500],Y[500][500];
void alignment(string &x, string &y){
	int match=3,mismatch=-3,d=-8,e=-1;

	//vector<vi>M(x.size()+1,vi(y.size()+1));
	//vector<vi>X(x.size()+1,vi(y.size()+1));
	//vector<vi>Y(x.size()+1,vi(y.size()+1));
	int i,j,k;
	X[0][0]=Y[0][0]=SHRT_MIN/2;
	for(i=1;i<=x.size();i++){
		M[i][0]=SHRT_MIN/2;
		X[i][0]=d+e*(i-1);
		Y[i][0]=SHRT_MIN/2;
	}
	for(j=1;j<=y.size();j++){
		M[0][j]=SHRT_MIN/2;
		X[0][j]=SHRT_MIN/2;
		Y[0][j]=d+e*(j-1);
	}
	for(i=1;i<=x.size();i++){
		for(j=1;j<=y.size();j++){
			vector<int> Z={M[i-1][j-1],X[i-1][j-1],Y[i-1][j-1]};
			M[i][j]=*max_element(Z.begin(),Z.end())+(x[i-1]==y[j-1]?match:mismatch);
			X[i][j]=max(M[i-1][j]+d,X[i-1][j]+e);
			Y[i][j]=max(M[i][j-1]+d,Y[i][j-1]+e);
		}
	}
	cout<<M[x.size()][y.size()]<<endl;
}
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s,z,t;
	for(;cin>>s>>z>>t;)alignment(s,t);
}