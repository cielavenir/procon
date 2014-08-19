#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
string x,y;

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

void solve(string &exp){
	int i=0,j,r;
	vector<string> token = split(exp,"|");
	for(;i<token.size();i++){
		string t=token[i].substr(1,token[i].size()-2);
		vector<string> prob = split(t,"&");
		for(r=j=0;j<prob.size();j++){
			if(prob[j][0]!='~'&&find(prob.begin(),prob.end(),y+prob[j])!=prob.end())r++;
		}
		if(!r)break;
	}
	puts(i==token.size()?"no":"yes");
}
int main(){x="#",y="~";for(string str;getline(cin,str),str!=x;solve(str));}