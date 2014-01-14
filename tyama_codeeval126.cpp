#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
int M;
int alignment(string &x, string &y){
	vector<vi>a(x.length()+1,vi(y.length()+1));
	int i,j,k;
	for(i=1;i<a.size();i++){a[i][0]=a[i-1][0]-1;}
	for(j=1;j<a[0].size();j++){a[0][j]=a[0][j-1]-1;}
	for(i=1;i<a.size();i++){
		for(j=1;j<a[0].size();j++){
			int Z[]={x[i-1]==y[j-1]?a[i-1][j-1]:(a[i-1][j-1]-1),a[i-1][j]-1,a[i][j-1]-1};
			int *z=max_element(Z,Z+3);
			a[i][j]=*z;
		}
	}
	return -a[x.length()][y.length()];
}
//int alignment(string &x, string &y){
//	int m=0,j=0;
//	for(;j<x.size();j++)m+=x[j]!=y[j];
//	return m;
//}
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int m,L,l,i,j;
	string S,D;
	for(;cin>>S>>M>>D;){
		l=S.size();
		L=D.size();
		vector<pair<int,string> >v;
		for(i=0;i<=L-l;i++){
			string D0=D.substr(i,l);
			if((m=alignment(S,D0))<=M)v.push_back(make_pair(m,D0));
		}
		if(v.empty()){
			cout<<"No match\n";
		}else{
			sort(v.begin(),v.end());
			//v.erase(unique(v.begin(),v.end()),v.end());
			for(i=0;i<v.size();i++)cout<<v[i].second<<(i<v.size()-1?" ":"\n");
		}
	}
}