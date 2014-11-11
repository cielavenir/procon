#include <iostream>
#include <sstream>
#include <string>
#include <regex>
using namespace std;

int main(){
	string line;
	for(;getline(cin,line);){
		istringstream ss(line);
		string pat,s;
		ss>>s;
		for(int i=0;i<s.size();i++){
			if(s[i]=='*')pat+=".*";
			else if(s[i]=='?')pat+=".";
			else if(s[i]=='[')pat+="[";
			else if(s[i]==']')pat+="]";
			else{
				if(!('a'<=s[i]&&s[i]<='z') && !('A'<=s[i]&&s[i]<='Z') && !('0'<=s[i]&&s[i]<='9'))pat+="\\";
				pat+=s[i];
			}
		}
		regex re(pat,regex_constants::basic);
		int cnt=0;
		for(;ss>>s;){
			if(regex_match(s,re)){
				if(cnt)cout<<' ';
				cout<<s;
				cnt++;
			}
		}
		if(!cnt)cout<<'-';
		cout<<endl;
	}
}