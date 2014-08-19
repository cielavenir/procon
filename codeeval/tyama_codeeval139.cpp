#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
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

string months[]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
int main(int argc, char **argv){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string line;
	for(;getline(cin,line);){
		vector<int> v(12*31);
		{
			vector<string> a=split(line,";");
			for(int i=1;i<a.size();i++)a[i]=a[i].substr(1);
			for(int i=0;i<a.size();i++){
				int j=(strtol(a[i].substr(4,4).c_str(),NULL,10)-1990)*12+distance(months,find(months,months+12,a[i].substr(0,3)));
				int k=(strtol(a[i].substr(13,4).c_str(),NULL,10)-1990)*12+distance(months,find(months,months+12,a[i].substr(9,3)));
				for(;j<=k;j++)v[j]=1;
			}
		}
		int r=0;
		for(int i=0;i<v.size();i++)r+=v[i];
		printf("%d\n",r/12);
	}
}