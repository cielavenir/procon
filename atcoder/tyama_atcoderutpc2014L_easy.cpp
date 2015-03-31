//#include "inspect.hpp"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
	string s;
	cin>>s;
	unordered_map<char,int>m;
	vector<vector<char> >v;
	int n=0;
	{
		vector<char> tmp;
		for(int i=0;i<s.size();i++){
			if(s[i]>='A'){
				tmp.push_back(s[i]);
				if(m.find(s[i])==m.end())m[s[i]]=n++;
			}
			if(s[i]=='+')v.push_back(tmp),tmp.clear();
		}
		v.push_back(tmp);
	}
	if(n>20)return 1;
	long long mi=1LL<<61;
	int minum=0;
	for(int i=0;i<1<<n;i++){
		long long ret=0;
		for(auto &e:v){
			long long x=1;
			for(auto &f:e)x*=(i&1<<m[f])?1:-1;
			ret+=x;
		}
		if(mi>ret)mi=ret,minum=0;
		if(mi==ret)minum++;
	}
	cout<<minum<<endl;
}