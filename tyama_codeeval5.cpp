#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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
main(){
	string s;
	int i,j;
	for(;getline(cin,s);){
		vector<string>a=split(s," ");
		reverse(a.begin(),a.end());
		for(i=1;i<=a.size()/2;i++){
			for(j=0;j<i;j++)if(a[j]!=a[j+i])break;
			if(j==i)break;
		}
		for(i--;i>=0;i--){
			cout<<a[i];
			if(i>0)cout<<' ';
		}
		cout<<endl;
	}
}