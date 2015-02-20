#include <regex>
#include <iostream>
#include <string>
using namespace std;
int main(){
	string s,t;
	smatch m;
	for(;getline(cin,s);){
		int ret=999,idx=0;
		for(;idx!=string::npos;){
			regex_search(s,m,regex("X(\\.*?)Y"));
			ret=min(ret,(int)m[1].length());
			idx=s.find_first_of(',');
			if(idx!=string::npos)s=s.substr(idx+1);
		}
		cout<<ret<<endl;
	}
}