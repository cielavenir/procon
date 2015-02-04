#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	string s;
	int A,B,C;
	for(cin>>s>>A;A--;){
		cin>>B>>C;
		reverse(s.begin()+(B-1),s.begin()+C);
	}
	cout<<s<<endl;
}