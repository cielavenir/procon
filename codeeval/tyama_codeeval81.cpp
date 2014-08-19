#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;
vector<int> split(string &str, const char *delim){
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
vector<int>a;
vector<int>v;
int r;
void D(int c, int d){
	if(d==4){
		int i=0,x=0;
		for(;i<4;i++)x+=v[i];
		if(x==0)r++;
	}else{
		for(;c<a.size();c++){
			v.push_back(a[c]);
			D(c+1,d+1);
			v.pop_back();
		}
	}
}
main(){
	string line;
	for(;getline(cin,line);){
		r=0;v.clear();
		a=split(line,",");
		D(0,0);
		cout<<r<<endl;
	}
}