#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

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

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int i;
	string line;
	for(;getline(cin,line);){
		vector<int>a=split_int(line,",");
		sort(a.begin(),a.end());
		cout<<a[1]-a[0];
		for(i=1;i<a.size()-1;i++)cout<<','<<a[i+1]-a[i];
		cout<<endl;
	}
}