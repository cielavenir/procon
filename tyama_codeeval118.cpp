#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>
using namespace std;

vector<string> split(string &str, const char *delim){
	vector<string> result;
	int cutAt;
	while( (cutAt = str.find_first_of(delim)) != str.npos ){
		if(cutAt > 0){
			result.push_back(str.substr(0, cutAt));
		}
		str = str.substr(cutAt + 1);
	}
	if(str.length() > 0){
		result.push_back(str);
	}
	return result;
}
vector<int> split_int(string &str, const char *delim){
	vector<int> result;
	int cutAt;
	while( (cutAt = str.find_first_of(delim)) != str.npos ){
		if(cutAt > 0){
			result.push_back(strtol(str.substr(0, cutAt).c_str(),NULL,10));
		}
		str = str.substr(cutAt + 1);
	}
	if(str.length() > 0){
		result.push_back(strtol(str.c_str(),NULL,10));
	}
	return result;
}

bool dfs(vector<vector<int> >&v,int d,set<int>&s){
	if(d==v.size())return true;
	for(int i=0;i<v[d].size();i++){
		if(s.find(v[d][i])==s.end()){
			s.insert(v[d][i]);
			if(dfs(v,d+1,s))return true;
			s.erase(v[d][i]);
		}
	}
	return false;
}
template<typename T>struct less_size{
	bool operator()(const vector<T>&l, const vector<T>&r) const{return l.size()<r.size();}
};
int main(){
	int n,i;
	string line;
	for(;getline(cin,line);){
		vector<vector<int> >v;
		{
			vector<string>a=split(line,";");
			n=strtol(a[0].c_str(),NULL,10);
			vector<string>b=split(a[1],"]");
			b[0]=b[0].substr(1);
			for(i=1;i<b.size();i++)b[i]=b[i].substr(2);
			for(i=0;i<b.size();i++){
				vector<string>c=split(b[i],"[");
				vector<int>d=split_int(c[1],",");
				//if(i%2==0){
					//sort(d.begin(),d.end(),greater<int>());
				//}else{
					sort(d.begin(),d.end());
				//}
				//z=strtol(c[0].c_str(),NULL,10);
				v.push_back(d);
			}
		}
		sort(v.begin(),v.end(),less_size<int>());
		set<int>s;
		cout<<(dfs(v,0,s)?"Yes":"No")<<endl;
	}
}