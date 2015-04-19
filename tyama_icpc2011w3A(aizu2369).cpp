#include <iostream>
using namespace std;
main(){
	int f=1,i;
	string s;
	for(cin>>s;f;)for(f=0,i=1;i<s.size()-3;i++)if(s.substr(i,3)=="mew")s.replace(i,3,""),f=1;
	cout<<(s=="mew"?"Cat":"Rabbit")<<endl;
}