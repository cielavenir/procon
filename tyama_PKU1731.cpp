#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
main(){
	string s;
	cin>>s;
	sort(s.begin(),s.end());
	do{cout<<s<<endl;}while(next_permutation(s.begin(),s.end()));
}