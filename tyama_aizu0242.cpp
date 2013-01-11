#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int main(){
	int n,i;
	char c;
	string s,t;
	for(;cin>>n,n;){
		getline(cin,s);
		map<char,map<string,int> >m;
		for(i=0;i<n;i++){
			string s,t;
			getline(cin,s);
			istringstream is(s);
			for(;is>>t;)m[t[0]][t]--;
		}
		cin>>c;
		vector<pair<int,string> >v;
		map<string,int>::iterator it=m[c].begin();
		for(;it!=m[c].end();it++)
			v.push_back(make_pair(it->second,it->first));
		sort(v.begin(),v.end());
		if(v.empty())cout<<"NA"<<endl;
		else{
			for(i=0;i<5&&i<v.size();i++){
				if(i)cout<<' ';
				cout<<v[i].second;
			}
			cout<<endl;
		}
	}
}