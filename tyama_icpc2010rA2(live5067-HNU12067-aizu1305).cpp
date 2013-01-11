#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <sstream>
using namespace std;
set<string>s;
set<string>visit;
map<string,vector<string> >m;
void S(string&key){
	vector<string>&z=m[key];
	for(int i=0;i<z.size();i++)
		if(m.find(z[i])==m.end())s.insert(z[i]);
		else if(visit.find(z[i])==visit.end()) /////
			visit.insert(z[i]),S(z[i]); ///// avoid recursive lol
}
main(){
	string str,group,g1,arg;
	for(int n,i,j;cin>>n,n;visit.insert(g1),S(g1),cout<<s.size()<<endl)
		for(m.clear(),s.clear(),visit.clear(),i=0;i<n;i++){
			for(cin>>str,j=0;j<str.length();j++)if(str[j]==':'||str[j]==','||str[j]=='.')str[j]=' ';
			istringstream is(str);
			vector<string>v;
			is>>group;
			if(!i)g1=group;
			for(;is>>arg;)v.push_back(arg);
			m[group]=v;
		}
}