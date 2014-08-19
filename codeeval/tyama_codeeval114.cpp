#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
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
	string line,result;
	int i,j,maweight,capacity,mavalue;
	for(;getline(cin,line);cout<<result<<endl){
		result="-";
		mavalue=maweight=0;
		vector<pair<int,int> >v;
		{
			vector<string>a=split(line,":");
			capacity=strtol(a[0].c_str(),NULL,10)*100;
			string b=a[1].substr(1);
			vector<string>c=split(b," ");
			for(i=0;i<c.size();i++){
				string d=c[i].substr(1,c[i].size()-2);
				vector<string>e=split(d,",");
				vector<string>f=split(e[1],".");
				int g=strtol(f[0].c_str(),NULL,10)*100+strtol(f[1].c_str(),NULL,10)*(f[1].size()==1?10:1);
				v.push_back(make_pair(g,strtol(e[2].substr(1).c_str(),NULL,10)));
			}
		}
		for(i=0;i<1<<v.size();i++){
			int value,weight;
			vector<int>idx;
			for(value=weight=j=0;j<v.size();j++){
				if(i&(1<<j)){
					weight+=v[j].first;
					value+=v[j].second;
					idx.push_back(j+1);
				}
			}
			if(weight<=capacity&&(mavalue<value||(value==mavalue&&weight<maweight))){
				mavalue=value;
				maweight=weight;
				ostringstream ss;
				for(j=0;j<idx.size();j++){
					if(j)ss<<',';
					ss<<idx[j];
				}
				result=ss.str();
			}
		}
	}
}