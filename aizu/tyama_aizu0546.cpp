#include<vector>
#include<map>
#include<string>
#include<iostream>
#include<numeric>
#include<algorithm>
using namespace std;
int main(){for(int n,k;cin>>n>>k&&n;){
	vector<string> v;string s;
	for(;n;n--)cin>>s,v.push_back(s);
	map<string,int>m;
	sort(v.begin(),v.end());
	do{
		m[accumulate(v.begin(),v.begin()+k,string(),[](const string &x,const string &y){return x+y;})]=1;
		//next_partial_permutation: http://origin.googlecode.com/svn-history/r366/trunk/core/include/origin/algorithm/boost_combination.hpp
		if(!k)break;
		reverse(v.begin()+k,v.end());
	}while(next_permutation(v.begin(),v.end()));
	cout<<m.size()<<endl;
}}
