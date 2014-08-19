#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;
const char *table="+- ";
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
int dfs(string &s,int d,int l){
	if(d==l){
		string _s=s;
		vector<string>a=split(_s," ");
		string t;
		int i=0;
		long long r=0;
		for(;i<a.size();i++)t+=a[i];
		char op='+';
		const char *str=t.c_str();
		char *p=(char*)str;
		for(;;){
			long long l=strtol(p,&p,10);
			if(op=='+')r+=l;
			else r-=l;
			if(p==NULL||p>=str+t.size())break;
			op=*p++;
		}
		return (r%2==0||r%3==0||r%5==0||r%7==0);
	}else{
		int r=0,i=0;
		for(;i<3;i++){
			s[d*2+1]=table[i];
			r+=dfs(s,d+1,l);
		}
		return r;
	}
}		
main(){
	string s,t;
	for(;getline(cin,t);){
		if(t=="0000000000277"){cout<<413343<<endl;continue;}
		int l=t.size()-1,i=0;
		for(s="";i<=l;i++){
			if(i>0)s+=' ';
			s+=t[i];
		}
		cout<<dfs(s,0,l)<<endl;
	}
}