#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
	map<string,int>m;
	int N,T,X;
	string s;
	for(cin>>N;N--;){
		cin>>T>>s;
		if(T==1)cin>>X,m[s]+=X;
		if(T==2)m.erase(s);
		if(T==3)cout<<m[s]<<endl;
	}
}