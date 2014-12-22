#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	int n;
	string s;
	for(cin>>n;n--;){
		cin>>s;
		auto it=unique(s.begin(),s.end());
		cout<<s.size()-distance(s.begin(),it)<<endl;
	}
}