#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;
typedef pair<int,int> pii;

vector<string> split(string &str, const char *delim){
	vector<string> result;
	int cutAt;
	while( (cutAt = str.find_first_of(delim)) != str.npos ){
		//if(cutAt > 0){
			result.push_back(str.substr(0, cutAt));
		//}
		str = str.substr(cutAt + 1);
	}
	//if(str.length() > 0){
		result.push_back(str);
	//}
	return result;
}

int main(){
	int i,j,l;
	cin.tie(0);
	ios::sync_with_stdio(false);
	string line;
	for(;getline(cin,line);){
		vector<string>a=split(line,";");
		vector<string>b=split(a[0]," ");
		vector<string>c=split(a[1]," ");
		for(i=j=0;i<b.size();i++){
			if(j<c.size()&&(l=b[i].find(c[j]))!=string::npos){
				b[i]=string(l,'_')+c[j]+string(b[i].size()-l-c[j].size(),'_');
				j++;
			}else{
				b[i]=string(b[i].size(),'_');
			}
		}
		if(j<c.size())puts("I cannot fix history");
		else for(i=0;i<b.size();i++)printf(i<b.size()-1?"%s ":"%s\n",b[i].c_str());
	}
}