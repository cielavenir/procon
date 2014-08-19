#include <vector>
#include <string>
#include <iostream>
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
		result.push_back(str.c_str());
	}
	return result;
}
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
int d[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
main(){
	string line;
	int i,j,k,r;
	for(;getline(cin,line);){
		vector<string>z=split(line,";");
		vector<int>b=split_int(z[0],",");
		int &h=b[0],&w=b[1];
		vector<string>a;
		for(i=0;i<h;i++)a.push_back(z[1].substr(w*i,w));
		for(i=0;i<h;i++){
			for(j=0;j<w;j++){
				if(a[i][j]=='*')cout<<'*';
				else{
					for(k=r=0;k<8;k++)if(0<=i+d[k][0]&&i+d[k][0]<h && 0<=j+d[k][1]&&j+d[k][1]<w && a[i+d[k][0]][j+d[k][1]]=='*')r++;
					cout<<r;
				}
			}
		}
		cout<<endl;
	}
}