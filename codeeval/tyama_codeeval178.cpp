#include <iostream>
#include <string>
#include <vector>
#include <cmath>
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

int main(){
	string line;
	for(;getline(cin,line);){
		vector<string> a=split(line," ");
		int n=sqrt(a.size());
		for(int i=0;i<n;i++)for(int j=0;j<n;j++){
			if(i|j)cout<<' ';
			cout<<a[(n-j-1)*n+i];
		}
		cout<<endl;
	}
}