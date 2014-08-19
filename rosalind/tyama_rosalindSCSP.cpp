//alignment library in C++11 (raw translate of Ruby version)
//only linear gap penalty is supported.
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <tuple>
using namespace std;
typedef vector<int> vi;
typedef tuple<int,int,int> tiii;
typedef vector<tiii> vtiii;
void alignment(string &x, string &y){
	vector<vi>a(x.length()+1,vi(y.length()+1));
	vector<vtiii>back(x.length()+1,vtiii(y.length()+1));
	string tx,ty;
	int i,j,k;
	for(i=1;i<a.size();i++){a[i][0]=a[i-1][0]-2;back[i][0]=make_tuple(i-1,0,0);}
	for(j=1;j<a[0].size();j++){a[0][j]=a[0][j-1]-2;back[0][j]=make_tuple(0,j-1,1);}
	for(i=1;i<a.size();i++){
		for(j=1;j<a[0].size();j++){
			vi Z{x[i-1]==y[j-1]?a[i-1][j-1]+2:(a[i-1][j-1]-9),a[i-1][j]-2,a[i][j-1]-2};
			vi::iterator z=max_element(Z.begin(),Z.end());
			a[i][j]=*z;
			switch(z-Z.begin()){
				case 0: back[i][j]=make_tuple(i-1,j-1,2);break;
				case 1: back[i][j]=make_tuple(i-1,j  ,0);break;
				case 2: back[i][j]=make_tuple(i  ,j-1,1);break;
			}
		}
	}
	int n=x.length(),m=y.length();
	vi t;
	for(;n||m;){
		t.push_back(get<2>(back[n][m]));
		int z=get<0>(back[n][m]);
		m=get<1>(back[n][m]);
		n=z;
	}
	reverse(t.begin(),t.end());
	for(k=i=j=0;k<t.size();k++){
		switch(t[k]){
			case 2: tx+=x[i++];ty+=y[j++];break;
			case 0: tx+=x[i++];ty+='-';   break;
			case 1: tx+='-';   ty+=y[j++];break;
		}
	}
	for(i=0;i<tx.length();i++)cout<<(tx[i]=='-'?ty[i]:tx[i]);
	cout<<endl;
}
int main(){
	string s,t;
	cin>>s>>t;
	alignment(s,t);
}