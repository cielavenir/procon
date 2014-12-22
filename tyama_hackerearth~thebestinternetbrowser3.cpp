#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(){
	int N;
	for(cin>>N;N--;){
		string s;
		cin>>s;
		int n=s.size();
		s=s.substr(4,n-4-4);
		int x=4;
		for(int i=0;i<s.size();i++)x+=strchr("aeiou",s[i])==NULL;
		cout<<x<<'/'<<n<<endl;
	}
}