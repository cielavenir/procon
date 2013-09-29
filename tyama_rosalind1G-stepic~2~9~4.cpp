#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
const char *bases="ATGC";
string s;
vector<string> t_max;
int c_max,K,D;
void dfs(string &t,int k){
	if(k==K){
		int i=0,j,d,c=0;
		for(;i<s.size()-k;i++){
			for(d=j=0;j<k;j++)d+=s[i+j]!=t[j];
			if(d<=D)c++;
		}
		if(c_max<c)c_max=c,t_max.clear();
		if(c_max==c)t_max.push_back(t);
	}else{
		int i=0;
		for(;i<4;i++){
			t+=bases[i];
			dfs(t,k+1);
			t.pop_back();
		}
	}
}
int main(){
	cin>>s>>K>>D;
	string t;
	dfs(t,0);
	int i=0;
	for(;i<t_max.size();i++){
		if(i)cout<<' ';
		cout<<t_max[i];
	}
	cout<<endl;
}