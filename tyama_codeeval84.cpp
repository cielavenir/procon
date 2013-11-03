#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;
main(){
	int o,c,S,h,i;
	bool fleft,fright;
	string s;
	for(;getline(cin,s);puts(fleft&&fright?"YES":"NO")){
		fleft=fright=true;
		o=c=S=h=0;
		for(i=0;i<s.size();i++){
			if(s[i]=='('){
				o++;
			}else if(s[i]==')'){
				c++;
				if(o+S-c<0){fleft=false;break;}
			}else if(s[i]==':'&&i<s.size()-1){
				if(s[i+1]=='(')S++,i++;
				else if(s[i+1]==')')h++,i++;
			}
		}
		o=c=S=h=0;
		if(fleft)for(i=s.size()-1;i>=0;i--){
			if(s[i]=='('){
				if(i>0&&s[i-1]==':')S++,i--;
				else{
					o++;
					if(c+h-o<0){fright=false;break;}
				}
			}else if(s[i]==')'){
				if(i>0&&s[i-1]==':')h++,i--;
				else c++;
			}
		}
	}
}