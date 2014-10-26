#include <iostream>
#include <string>
using namespace std;

int main(){
	string line;
	for(;getline(cin,line);){
		if(line.size()<=55)cout<<line<<endl;
		else{
			int idx=40;
			for(;idx&&line[idx]!=' ';)idx--;
			if(idx==0)idx=40;
			cout<<line.substr(0,idx)+"... <Read More>"<<endl;
		}
	}
}