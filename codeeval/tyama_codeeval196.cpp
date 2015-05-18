#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(){
	string line,s;
	for(;getline(cin,line);){
		istringstream ss(line);
		bool f=false;
		for(;ss>>s;){
			if(f)cout<<' ';
			f=true;
			swap(s[0],s[s.size()-1]);
			cout<<s;
		}
		cout<<endl;
	}
}