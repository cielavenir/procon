#pragma GCC optimize("O3")
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <random>
#include <algorithm>
#include <ctime>
#include <unistd.h>
using namespace std;

vector<vector<int>>m;

int lcs(const string &a,const string &b){
if(0){
/*
	vector<vector<int>>m(a.size()+1);
	for(auto &e:m)e.resize(b.size()+1);
*/
	for(int i=1;i<=a.size();i++){
		for(int j=1;j<=b.size();j++){
			m[i][j]=max(max(m[i-1][j],m[i][j-1]),m[i-1][j-1]+(a[i]==b[j]));
		}
	}
	return m[a.size()][b.size()];
}else{
	int R=0,r=0,i=0;
	for(auto &bc:b){
		if(r<a.size()&&a[r]==bc)r++,R+=b.size()*b.size()-i*i;
		i++;
	}
	return R;
}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	const double D=2.5;
	int N,M,Q;
	cin>>N>>M>>Q;

	m.resize(8);
	for(auto &e:m)e.resize(8);
	mt19937_64 engine((unsigned int)time(NULL)^(getpid()<<16));
	int Mz=min(M,3);
	string v(26,' ');
	if(v.size()<Mz)return 1;
	iota(v.begin(),v.end(),97);
	shuffle(v.begin(),v.end(),engine);
	string S=v.substr(0,Mz),s=S;
	set<string>h;h.insert(S);
	for(int i=Mz;i<N;i++){
		string t=s.substr(1)+' ';
		shuffle(v.begin(),v.end(),engine);
		for(auto &e:v){
			if(e==t[Mz-2])continue;
			t[Mz-1]=e;
			if(h.find(t)==h.end()){
				S.push_back(e);
				h.insert(t);
				break;
			}
		}
		s=move(t);
	}
	cerr<<S<<endl;
	cout<<S<<endl;
	cout<<D<<endl;
	S+=S;
	vector<string>q(Q);
	for(auto &e:q)cin>>e;
	for(auto &q0:q){
		int v=-1,idx=-1;
		for(int j=0;j<N;j++){
			string s0=S.substr(j,M*3);
			int v0=lcs(q0,s0);
			if(v0>v){
				v=v0;
				idx=j;
			}
		}
		cout<<idx<<endl;
	}
}
