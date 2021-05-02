#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int mk(string &t,int a,int b){
	string s=t;
	s[a]=b+'0';
	return strtol(s.c_str(),NULL,10);
}
int mk(string &s){
	return strtol(s.c_str(),NULL,10);
}
int main(){
	string A,B;
	cin>>A>>B;
	vector<int>v={
		mk(A)-mk(B),
		mk(A,0,9)-mk(B),
		mk(A,1,9)-mk(B),
		mk(A,2,9)-mk(B),
		mk(A)-mk(B,0,1),
		mk(A)-mk(B,1,0),
		mk(A)-mk(B,2,0),
	};
	printf("%d\n",*max_element(v.begin(),v.end()));
}