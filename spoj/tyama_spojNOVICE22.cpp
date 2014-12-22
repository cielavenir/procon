#include <iostream>
#include <string>
#include <set>
using namespace std;
main(){
	int t;
	string s;
	for(cin>>t;t--;){
		cin>>s;
		set<char>se;
		for(int i=0;i<s.size();i++)se.insert(s[i]);
		printf("%d\n",se.size());
	}
}