// http://qiita.com/Nabetani/items/4c21127f07bfa68fa1f8
// http://nabetani.sakura.ne.jp/hena/ord29devdice/

#include <iostream>
#include <string>
#include <set>
#include <regex>
#include <algorithm>
#include <functional>
using namespace std;

char rot_face(char f){
	string key="D2T3S6114455";
	int idx=key.find_first_of(f);
	if(idx==string::npos)abort();
	return key[idx^1];
}

string rot_dice(const string&s){
	return string()+rot_face(s[5])+s[0]+s[1]+'/'+rot_face(s[4])+rot_face(s[2])+rot_face(s[6]);
}

string rev(string s){ //参照渡し不可
	reverse(s.begin(),s.end());
	return s;
}

bool enum_patterns(set<string>&pattern,const function<bool(const string&)>&blk,const string &c="146/53D"){
	if(pattern.find(c)!=pattern.end())return true;
	pattern.insert(c);
	if(!blk(c))return false;
	if(!enum_patterns(pattern,blk,rev(c)))return false;
	if(!enum_patterns(pattern,blk,rot_dice(c)))return false;
	return true;
}

int main(){
	string src;
	for(;getline(cin,src);){
		string target=src;
		for(int i=0;i<target.size();i++)if('w'<=target[i]&&target[i]<='z')target[i]='.';
		regex re(target);
		string answer;
		set<string>pattern;

		if(!enum_patterns(pattern,[&](const string &s)->bool{
			if(regex_match(s,re)){
				if(answer.empty()){answer=s;return true;}
				return false;
			}
			return true;
		})){
			cout<<"many"<<endl;
		}else if(answer.empty()){
			cout<<"none"<<endl;
		}else{
			string ret;
			for(int i=0;i<src.size();i++){
				if(src[i]!=answer[i]){
					if(!ret.empty())ret+=',';
					ret=ret+src[i]+'='+answer[i];
				}
			}
			cout<<ret<<endl;
		}
	}
}