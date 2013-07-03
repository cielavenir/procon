#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
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
	int i;
	for(;getline(cin,line);){
		vector<string> a=split(line,"|");
		vector<string> b=split(a[1]," ");
		for(i=0;i<b.size();i++)cout<<a[0][strtol(b[i].c_str(),NULL,10)-1];
		cout<<endl;
	}
}