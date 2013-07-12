#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cassert>
using namespace std;
string data;
const char *str;
int parse(int i){
	if('0'<=data[i]&&data[i]<='9')return strtol(str+i,NULL,10)/2+1;
	assert(data[i]=='[');
	vector<int>v;
	int j=i,c=0;
	for(;;j++){
		if(data[j]=='[')if(++c==1)v.push_back(parse(j+1));
		if(data[j]==']')if(--c==-1)break;
	}
	sort(v.begin(),v.end());
	for(c=j=0;j<=v.size()/2;j++)c+=v[j];
	return c;
}
main(){
	int T;
	for(cin>>T,getline(cin,data);T--;cout<<parse(1)<<endl)getline(cin,data),str=data.c_str();
}