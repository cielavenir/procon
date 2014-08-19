#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
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

main(){
	int n,i,j;
	string s;
	for(;cin>>n;){
		vector<vector<int> >a;
		for(i=0;i<n;i++)cin>>s,a.push_back(split_int(s,","));
		for(i=1;i<n;i++)a[0][i]+=a[0][i-1],a[i][0]+=a[i-1][0];
		for(i=1;i<n;i++)for(j=1;j<n;j++)a[i][j]+=min(a[i-1][j],a[i][j-1]);
		cout<<a[n-1][n-1]<<endl;
	}
}