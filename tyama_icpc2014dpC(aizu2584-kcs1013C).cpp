#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string parse(string str){
	string ret;
	int i=0,j,cnt,acc=0;
	for(;i<str.size();i++){
		if(str[i]=='['){
			cnt=1;
			for(j=i+1;cnt;j++){
				if(str[j]=='[')cnt++;
				if(str[j]==']')cnt--;
			}
			string x=parse(str.substr(i+1,(j-1)-(i+1)));
			reverse(x.begin(),x.end());
			ret+=x;
			i=j-1;
		}else if(str[i]=='+'){
			acc++;
		}else if(str[i]=='-'){
			acc--;
		}else{
			ret+=str[i]=='?'?'A':( ((str[i]-'A'+acc)%26+26)%26+'A' );
			acc=0;
		}
	}
	return ret;
}

int main(){
	string line;
	for(;getline(cin,line),line!=".";){
		line=parse(line);
		cout<<line<<endl;
	}
}