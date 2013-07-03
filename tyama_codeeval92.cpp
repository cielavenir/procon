#include <vector>
#include <string>
#include <iostream>
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
	string line;
	for(;getline(cin,line);){
		vector<string> a=split(line," ");
		cout<<a[a.size()-2]<<endl;
	}
}