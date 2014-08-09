#include <iostream>
#include <string>
using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string line,z;
	for(;getline(cin,line);){
		int f=0;
		for(int i=0;i<line.size();i++){
			if(
				('A'<=line[i]&&line[i]<='Z') ||
				('a'<=line[i]&&line[i]<='z')
			){
				if(f)line[i]|=0x20;
				else line[i]&=0xdf;
				f^=1;
			}
		}
		cout<<line<<endl;
	}
}