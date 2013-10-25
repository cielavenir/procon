#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
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
int main(){
	string line;
	int f,i,j;
	vector<int>hole(2);
	vector<int>box(3);
	for(;getline(cin,line);){
		f=0;
		vector<string>a=split(line,"|");
		{
			vector<string>a1=split(a[0]," ");
			vector<vector<int> >a2;
			for(i=0;i<a1.size();i++){
				string s=a1[i].substr(1,a1[i].size()-2);
				a2.push_back(split_int(s,","));
			}
			hole[0]=abs(a2[0][0]-a2[1][0]);
			hole[1]=abs(a2[0][1]-a2[1][1]);
			sort(hole.begin(),hole.end());
		}
		vector<string>b=split(a[1],";");
		for(j=0;j<b.size();j++){
			string s=b[j].substr(1,b[j].size()-2);
			vector<string>b1=split(s," ");
			vector<vector<int> >a2;
			for(i=1;i<b1.size();i++){
				string s=b1[i].substr(1,b1[i].size()-2);
				a2.push_back(split_int(s,","));
			}
			box[0]=abs(a2[0][0]-a2[1][0]);
			box[1]=abs(a2[0][1]-a2[1][1]);
			box[2]=abs(a2[0][2]-a2[1][2]);
			sort(box.begin(),box.end());
			if(box[0]<=hole[0]&&box[1]<=hole[1]){
				if(f)cout<<',';
				f=1;
				cout<<b1[0];
			}
		}
		if(!f)cout<<'-';
		cout<<endl;
	}
}