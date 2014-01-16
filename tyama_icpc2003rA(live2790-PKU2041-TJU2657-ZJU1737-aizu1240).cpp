//pku 2041
//std::stringのれんしぅでしゅ
 
#include <iostream>
#include <algorithm>
#define between(n,x,m) (((n)<=(x))&&((x)<=(m)))
using namespace std;

void J(string &str){rotate(str.begin(),str.begin()+(str.size()-1),str.end());}
void C(string &str){rotate(str.begin(),str.begin()+1,str.end());}
void E(string &str){
	int i=(str.size())/2;
	string tmp=str;
	str.replace(0,i,tmp,str.length()-i,i);
	str.replace(str.length()-i,i,tmp,0,i);
}

void A(string &str){reverse(str.begin(),str.end());}

void P(string &str){
	int i=str.size();
	for(;i>=0;--i){
		if(between('0',str[i],'9')){
			str[i]--;
			if(str[i]=='/')str[i]='9';
		}
	}
}

void M(string &str){
	int i=str.size();
	for(;i>=0;--i){
		if(between('0',str[i],'9')){
			str[i]++;
			if(str[i]==':')str[i]='0';
		}
	}
}


struct x{
	string &str;
	x(string &_str):str(_str){}
	void operator()(char c){
		switch(c){
			case 'J': J(str);break;
			case 'C': C(str);break;
			case 'E': E(str);break;
			case 'A': A(str);break;
			case 'P': P(str);break;
			default:  M(str);break;
		}
	}
};

int main(){
	string filter,str;
	int n;
	for(cin>>n;n--;cout<<str<<endl){
		cin>>filter>>str;
		for_each(filter.rbegin(), filter.rend(), x(str));
	}
}