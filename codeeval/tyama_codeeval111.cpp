#include <iostream>
#include <string>
#include <vector>
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
	int i,m;
	string s;
	for(;getline(cin,s);){
		vector<string>a=split(s," ");
		for(i=m=0;i<a.size();i++)if(a[i].size()>m)s=a[i],m=a[i].size();
		cout<<s<<endl;
	}
}