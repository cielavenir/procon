#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>
using namespace std;
typedef unordered_map<string,string> mss;

unordered_map<string,function<bool(const string&,const string&,mss&)>>T={
	{"child",[](const string &x,const string &y,mss &parent){return parent[x]==y;}},
	{"parent",[](const string &x,const string &y,mss &parent){return parent[y]==x;}},
	{"sibling",[](const string &x,const string &y,mss &parent){return parent[x]==parent[y];}},
	{"descendant",[](const string &x,const string &y,mss &parent){
		string z=parent[x];
		for(;;){
			if(z==y)return true;
			if(parent[z]=="")return false;
			z=parent[z];
		}
	}},
	{"ancestor",[](const string &x,const string &y,mss &parent){
		string z=parent[y];
		for(;;){
			if(z==x)return true;
			if(parent[z]=="")return false;
			z=parent[z];
		}
	}},

};
int main(){
	int N,Q;
	string line;
	for(;cin>>N>>Q,N;){
		getline(cin,line);
		mss parent;
		vector<string>stack;
		getline(cin,line);
		parent[line]="";
		stack.push_back(line);
		for(int i=1;i<N;i++){
			getline(cin,line);
			int idx=0;
			for(;line[idx]==' ';idx++);
			string name=line.substr(idx);
			if(idx>stack.size())return 1;
			for(;idx<stack.size();stack.pop_back());
			parent[name]=stack[stack.size()-1];
			stack.push_back(name);
		}
		for(int i=0;i<Q;i++){
			getline(cin,line);
			istringstream ss(line);
			string x,z,y;
			ss>>x>>y>>y>>z>>y>>y;
			y=y.substr(0,y.size()-1);
			cout<<(T[z](x,y,parent)?"True":"False")<<endl;
		}
		cout<<endl;
	}
}
