#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int M,m,L,l,i,j;
	string S,D;
	for(;cin>>S>>M>>D;){
		l=S.size();
		L=D.size();
		vector<pair<int,string> >v;
		for(i=0;i<=L-l;i++){
			for(m=j=0;j<l;j++)m+=S[j]!=D[i+j];
			if(m<=M)v.push_back(make_pair(m,D.substr(i,l)));
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