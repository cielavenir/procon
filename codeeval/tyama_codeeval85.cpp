#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cstdlib>
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

#define n A[0]
#define k A[1]
#define a A[2]
#define b A[3]
#define c A[4]
#define r A[5]
main(){
	int i,j;
	string s;
	for(;getline(cin,s);){
		vector<int>A=split_int(s,",");
		vector<int> m;
		m.push_back(a);
		for(i=1;i<k;i++)m.push_back((b*m[i-1]+c)%r);
		for(;i<n;i++){
			set<int>z;
			for(vector<int>::iterator it=m.begin();it!=m.end();++it)z.insert(*it);
			for(j=0;z.find(j)!=z.end();j++);
			m.push_back(j);
			m.erase(m.begin());
		}
		cout<<m[m.size()-1]<<endl;
	}
}