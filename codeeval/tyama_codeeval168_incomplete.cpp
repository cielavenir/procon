#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cassert>
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

int main(){
	string line;
	for(;getline(cin,line);){
		vector<int>v=split_int(line," ");
		assert(v.size()==2000);
		int prev=-1;
		vector<int>dec;
		for(int i=2;i<v.size()-2;i++){
			if(v[i-2]<=v[i]&&v[i]>v[i+2]){
				if(prev>=0)dec.push_back(i-prev);
				prev=i;
			}
		}
		sort(dec.begin(),dec.end());
		cout<< (200000/(dec[dec.size()-1])+50)/100*10 <<endl;
	}
}
/*
1unit=1/20000s=0.00005s

ex1:
1/(0.00005*64)=312.5
(200000/64+50)/100*10=310
ans=310Hz
*/