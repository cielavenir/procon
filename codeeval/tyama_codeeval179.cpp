#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int T[]={63, 6, 91, 79, 102, 109, 125, 7, 127, 111};

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
	string line;
	for(;getline(cin,line);){
		vector<string> a=split(line,";");
		vector<string> b=split(a[0]," ");
		vector<int> c(b.size());
		for(int i=0;i<b.size();i++){
			int r=0;
			for(int j=0;j<8;j++)r|=(b[i][j]-'0')<<j;
			c[i]=r;
		}
		vector<int> d;
		for(int i=0,j=0;i<a[1].size();i++){
			if(a[1][i]=='.'){
				d[j-1]|=0x80;
			}else{
				d.push_back(T[a[1][i]-'0']);
				j++;
			}
		}
		int i=0;
		for(;i<=c.size()-d.size();i++){
			int j=0;
			for(;j<d.size();j++)if((c[i+j]&d[j])!=d[j])break;
			if(j==d.size())break;
		}
		cout<<(i<=c.size()-d.size() ? 1 : 0)<<endl;
	}
}