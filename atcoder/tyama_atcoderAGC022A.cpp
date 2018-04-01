#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	string s;
	cin>>s;
	if(s.size()==26){
		string t=s;
		if(!next_permutation(t.begin(),t.end()))cout<<-1<<endl;
		else{
			for(int n=0;n<s.size();n++){
				if(s[n]!=t[n]){
					cout<<t.substr(0,n+1)<<endl;
					break;
				}
			}
		}
	}else{
		for(char c='a';c<='z';c++){
			if(all_of(s.begin(),s.end(),[&](char e){
				return e!=c;
			})){
				cout<<s<<c<<endl;
				break;
			}
		}
	}
}
