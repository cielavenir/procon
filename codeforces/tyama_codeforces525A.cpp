#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
	int N,r=0;
	cin>>N;
	string s;
	cin>>s;
	map<char,int>m;
	for(int i=0;i<N-1;i++){
		m[s[2*i]]++;
		char door=s[2*i+1]|32;
		if(!m[door])r++;
		else m[door]--;
	}
	cout<<r<<endl;
}