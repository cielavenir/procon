#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char,int> table={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string line;
	for(;getline(cin,line);){
		int r=0;
		for(int i=0;i<line.size();i+=2){
			int n=(line[i]-'0')*table[line[i+1]];
			if(i+2<line.size()&&table[line[i+1]]<table[line[i+3]])n=-n;
			r+=n;
		}
		cout<<r<<endl;
	}
}