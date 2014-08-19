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
int main(){
	string line;
	int i;
	for(;getline(cin,line);){
		vector<string>a=split(line,",");
		vector<string>words,digits;
		for(i=0;i<a.size();i++){
			if('0'<=a[i][0]&&a[i][0]<='9')digits.push_back(a[i]);
			else words.push_back(a[i]);
		}
		for(i=0;i<words.size();i++){
			if(i)cout<<',';
			cout<<words[i];
		}
		if(words.size()&&digits.size())cout<<'|';
		for(i=0;i<digits.size();i++){
			if(i)cout<<',';
			cout<<digits[i];
		}
		cout<<endl;
	}
}