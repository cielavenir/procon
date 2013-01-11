#include <regex>
#include <iostream>
#include <string>
using namespace std;
main(){
	int n;
	string s;
	smatch m;
	for(cin>>n,getline(cin,s);n;n--){
		getline(cin,s);
		if(regex_match(s,m,regex(">'(=+)#(=+)~"))&&m[1].length()==m[2].length())cout<<'A'<<endl;
		else if(regex_match(s,regex(">^(Q=)+~~")))cout<<'B'<<endl;
		else cout<<"NA"<<endl;
	}
}