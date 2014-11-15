#include <iostream>
#include <sstream>
#include <string>
using namespace std;

bool wildmatch(const char *pattern, const char *compare){
	switch(*pattern){
		case '?':
			return *compare&&wildmatch(pattern+1,compare+1);
		case '*':
			return wildmatch(pattern+1,compare)||(*compare&&wildmatch(pattern,compare+1));
		case '[':
			{
				bool f=false;
				for(pattern++;*pattern&&*pattern!=']';pattern++){
					if(*pattern==*compare)f=true;
				}
				if(!f)return false;
				return wildmatch(pattern+(*pattern==']'),compare+1);
			}
		default:
			if(!*pattern&&!*compare)return true;
			if(*pattern!=*compare)return false;
			return wildmatch(pattern+1,compare+1);
	}
}

int main(){
	string line;
	for(;getline(cin,line);){
		istringstream ss(line);
		string pat,s;
		ss>>pat;
		int cnt=0;
		for(;ss>>s;){
			if(wildmatch(pat.c_str(),s.c_str())){
				if(cnt)cout<<' ';
				cout<<s;
				cnt++;
			}
		}
		if(!cnt)cout<<'-';
		cout<<endl;
	}
}