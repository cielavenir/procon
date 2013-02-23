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
int alignment(vector<vi>&a, string &x, string y){
	vector<vtiii>back(x.length()+1,vtiii(y.length()+1));
	string tx,ty;
	int i,j,k;
	for(i=1;i<a.size();i++){a[i][0]=a[i-1][0]-1;back[i][0]=make_tuple(i-1,0,0);}
	for(j=1;j<a[0].size();j++){a[0][j]=a[0][j-1]-1;back[0][j]=make_tuple(0,j-1,1);}
	for(i=1;i<a.size();i++){
		for(j=1;j<a[0].size();j++){
			vi Z{x[i-1]==y[j-1]?a[i-1][j-1]:(a[i-1][j-1]-1),a[i-1][j]-1,a[i][j-1]-1};
			vi::iterator z=max_element(Z.begin(),Z.end());
			a[i][j]=*z;
			//switch(z-Z.begin()){
			//	case 0: back[i][j]=make_tuple(i-1,j-1,2);break;
			//	case 1: back[i][j]=make_tuple(i-1,j  ,0);break;
			//	case 2: back[i][j]=make_tuple(i  ,j-1,1);break;
			//}
		}
	}
}
int main(){
	string s,t;
	int k;
	cin>>k>>s>>t;
	k=-k;
	vector<vi>a(s.length()+1,vi(t.length()+1));
	int i=0,j;
	for(;i<t.length()-1;i++){
		alignment(a,s,t.substr(i));
		for(j=0;j<t.length()-i;j++){
			//cout<<"+++"<<i<<' '<<j<<' '<<a[s.length()][j]<<' '<<a[0][i]<<endl;
			if(a[s.length()][j]>=k)cout<<(i+1)<<' '<<(j-i)<<endl;
		}
		cerr<<i<<endl;
	}
}