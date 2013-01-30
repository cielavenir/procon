#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
main(int argc, char **argv){
	ifstream fin(argv[1]);
	int i,r;
	string s;
	for(;getline(fin,s);cout<<r<<endl){
		vector<int>v(26);
		for(i=0;i<s.size();i++){
			if('A'<=s[i]&&s[i]<='Z')v[s[i]-65]++;
			if('a'<=s[i]&&s[i]<='z')v[s[i]-97]++;
		}
		sort(v.begin(),v.end());
		for(r=i=0;i<26;)r+=v[i]*++i;
	}
}