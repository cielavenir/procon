#include <iostream>
#include <string>
#include <set>
using namespace std;
set<string>result;
void dfs(string s,string t){
	if(s.size()==1)result.insert(t+s[0]);
	else{
		dfs(s.substr(1),t+s[0]);
		dfs(s.substr(0,s.size()-1),t+s[s.size()-1]);
	}
}
int main(){
	string s;
	cin>>s;
	dfs(s,"");
	cout<<result.size()<<endl;
}