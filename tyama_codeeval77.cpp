#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
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

main(){
	int i,j;
	string line,z;
	for(;getline(cin,line);){
		vector<string>s=split(line,";");
		while(s.size()>1){
			pair<int,pair<int,int> >k=make_pair(0,make_pair(-1,-1));
			for(i=0;i<s.size();i++)for(j=0;j<s.size();j++)if(i!=j){
				int n=min(s[i].size(),s[j].size());
				for(;n>0&&s[i].substr(s[i].size()-n)!=s[j].substr(0,n);)n--;
				if(n>k.first)k=make_pair(n,make_pair(i,j));
			}
			if(k.first==0){
				z="";
				for(i=0;i<s.size();i++)if(z.size()<s[i].size())z=s[i];
				s[0]=z;
				break;
			}
			i=k.second.first,j=k.second.second;
			s.push_back(s[i]+s[j].substr(k.first));
			if(i<j)swap(i,j);
			s.erase(s.begin()+i);
			s.erase(s.begin()+j);
		}
		cout<<s[0]<<endl;
	}
}