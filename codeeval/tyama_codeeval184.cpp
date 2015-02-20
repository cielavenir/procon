#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int main(){
	int i,j;
	string str;
	cin.tie(0);
	ios::sync_with_stdio(false);
	//cin>>str;
for(;getline(cin,str);){str=str.substr(0,str.size()-1);
	vector<pair<char,int> >v(str.size()),sorted(str.size());
	for(i=0;i<str.size();i++)v[i]=sorted[i]=make_pair(str[i],i);
	sort(sorted.begin(),sorted.end());
	auto cur=sorted[0];
	string ret;
	for(i=1;i<str.size();i++){
		//auto it=find(v.begin(),v.end(),cur);
		//cur=sorted[it-v.begin()];
		cur=sorted[cur.second];
		ret+=cur.first;
	}
	ret+=sorted[0].first;
	int idx=ret.find_first_of('$');
	rotate(ret.begin(),ret.begin()+idx+1,ret.end());
	cout<<ret<<endl;
}}