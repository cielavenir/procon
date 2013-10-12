#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;
vector<double> split_double(string &str, const char *delim){
	vector<double> result;
	int cutAt;
	while( (cutAt = str.find_first_of(delim)) != str.npos ){
		if(cutAt > 0){
			result.push_back(strtod(str.substr(0, cutAt).c_str(),NULL));
		}
		str = str.substr(cutAt + 1);
	}
	if(str.length() > 0){
		result.push_back(strtod(str.c_str(),NULL));
	}
	return result;
}
vector<int> rec2c(vector<int>&a,int n){
	vector<int>ret;
	if(n==0){
		ret.push_back(0);
		return ret;
	}
	int i=0,j;
	for(;i<a.size();i++)if(n>=a[i]){
		for(j=0;j<a.size();j++)if((n-a[i])%a[j]==0)break;
		if(j<a.size()){
			ret=rec2c(a,n-a[i]);
			if(ret.size()){
				ret.push_back(a[i]);
				return ret;
			}
		}
	}
	return ret;//nil;
}
int main(){
	map<int,string>m;
	m[10000]="ONE HUNDRED";
	m[5000]="FIFTY";
	m[2000]="TWENTY";
	m[1000]="TEN";
	m[500]="FIVE";
	m[200]="TWO";
	m[100]="ONE";
	m[50]="HALF DOLLAR",
	m[25]="QUARTER";
	m[10]="DIME";
	m[5]="NICKEL";
	m[1]="PENNY";

	vector<int>keys;
	for(map<int,string>::iterator it=m.begin();it!=m.end();it++)keys.push_back(it->first);
	sort(keys.begin(),keys.end(),greater<int>());

	string line;
	for(;getline(cin,line);){
		vector<double>a=split_double(line,";");
		int n=((int)(a[1]*100)-(int)(a[0]*100));
		if(n<0)cout<<"ERROR"<<endl;
		else if(n==0)cout<<"ZERO"<<endl;
		else{
			vector<int>x=rec2c(keys,n);
			reverse(x.begin(),x.end());
			for(int i=0;i<x.size()-1;i++){
				if(i)cout<<",";
				cout<<m[x[i]];
			}
			cout<<endl;
		}
	}
}