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
	string line;
	int i,j,c,x;
	for(;getline(cin,line);){
		vector<int>z=split_int(line," ");
		for(i=0;i<10;i++){
			for(c=j=0;j<z.size();j++){
				if(z[j]==i)x=j+1,c++;
			}
			if(c==1){
				printf("%d\n",x);
				break;
			}
		}
		if(i==10)puts("0");
	}
}