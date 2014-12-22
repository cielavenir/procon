#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
//typedef pair<string,string> memo_type;
typedef string memo_type;

int compare(const string &a,const string &b){
	if(a.size()<b.size())return -1;
	if(a.size()>b.size())return 1;
	if(a<b)return -1;
	if(a>b)return 1;
	return 0;
}

class Solve{
	unordered_map<memo_type,int>memo;
	const string str;

	int dfs(const string s,const string prev){
		if(s=="")return 0;
		if(s[0]=='0')return -1;
		//memo_type p=make_pair(s,prev);
		memo_type p=s+'|'+prev;
		auto memo_it=memo.find(p);
		if(memo_it!=memo.end())return memo_it->second;
		int r=-1;
		for(int i=prev.size()-1;i<s.size();i++){
			string s0i=s.substr(0,i+1);
			if(compare(prev,s0i)<0){
				int x=dfs(s.substr(i+1),s0i);
				if(x>=0)r=max(r,x+1);
			}
		}
		return memo[p]=r;
	}

public:
	Solve(const string &_str): str(_str){}
	int run(){
		return dfs(str,"0");
	}
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string line;
	for(;getline(cin,line);)cout<<Solve(line).run()<<endl<<flush;
}