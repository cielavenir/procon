#include <iostream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
string shortestsuperstring(vector<string>&s){
	for(;s.size()>1;){
		int l=s.size();
		tuple<int,int,int>k=make_tuple(-1,-1,-1);
		for(int i=0;i<l;i++)for(int j=0;j<l;j++)if(i!=j){
			int n=min(s[i].size(),s[j].size());
			for(;n&&s[i].substr(s[i].size()-n)!=s[j].substr(0,n);n--);
			if(n>get<0>(k))k=make_tuple(n,i,j);
		}
		s.push_back(s[get<1>(k)]+s[get<2>(k)].substr(get<0>(k)));
		for(int i=l;i>=0;i--)if(i==get<1>(k)||i==get<2>(k))s.erase(s.begin()+i);
	}
	return s[0];
}
int main(){
	string t;
	vector<string>s;
	for(;getline(cin,t);)s.push_back(t);
	cout<<shortestsuperstring(s)<<endl;
}
