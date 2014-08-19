#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

vector<int> split_int(string str, const char *delim){
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
	cin.tie(0);
	ios::sync_with_stdio(false);
	int i,j,aend,bend;
	string line1,line2;
	for(;cin>>line1>>line2;){
		vector<int>a=split_int(line1.substr(1),",");
		vector<int>b=split_int(line2.substr(1),",");
		aend=a[a.size()-1],bend=b[b.size()-1];
		int result=0;
		for(i=0;i<a.size()-1;i++)for(j=0;j<b.size()-1;j++){
			//a[i]*bend/aend<b[j+1]
			//a[i+1]*bend/aend>b[j]
			result+=a[i]*bend<b[j+1]*aend&&a[i+1]*bend>b[j]*aend;
		}
		printf("%d\n",result);
	}
}