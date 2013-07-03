#include <vector>
#include <string>
#include <iostream>
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
	string line;
	int i;
	for(;getline(cin,line);){
		if(line.size()==0)continue;
		vector<string>c=split(line," ");
		reverse(c.begin(),c.end());
		if(!c.empty())cout<<c[0];
		for(i=1;i<c.size();i++)cout<<" "<<c[i];
		cout<<endl;
	}
}