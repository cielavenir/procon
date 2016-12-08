#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
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

void reversepoland(string &exp){
	vector<string> token = split(exp," ");
	vector<double> resolveNumber;
	vector<string> resolveString;
	for(int i=0;i<token.size();i++){
		char *p=NULL;
		double d=strtod(token[i].c_str(),&p);
		if(p-token[i].c_str()==token[i].size()){
			resolveNumber.push_back(d);
			resolveString.push_back(token[i]);
		}else{
			//if(resolveNumber.size()<2){printf("stack few\n");return;}
			double d2=resolveNumber[resolveNumber.size()-1],d1=resolveNumber[resolveNumber.size()-2];
			resolveNumber.pop_back(),resolveNumber.pop_back();
			string s2=resolveString[resolveString.size()-1],s1=resolveString[resolveString.size()-2];
			resolveString.pop_back(),resolveString.pop_back();
			double ret;

			if(token[i]=="+"){ret=d1+d2;}
			else if(token[i]=="-"){ret=d1-d2;}
			else if(token[i]=="*"){ret=d1*d2;}
			else if(token[i]=="/"){ret=d1/d2;}
			//else if(token[i]=="%"){ret=d1%d2;}
			//else if(token[i]=="**"){ret=pow(d1,d2);}
			//else{printf("unknown OP %s\n",token[i].c_str());return;}

			resolveNumber.push_back(ret);
			resolveString.push_back("("+s1+token[i]+s2+")"); //this won't emit "optimized" expression. full of parens.
		}
	}
	//if(resolveNumber.size()!=1){printf("result stack not 1");return;}
	printf("%.0f\n",resolveNumber[0]);
	//puts(resolveString[0].c_str());
}
int main(){string str;getline(cin,str);reversepoland(str);}
