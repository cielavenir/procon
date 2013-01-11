#include <iostream>
#include <string>
#include <map>
using namespace std;
string z(int i){string s="";if(i>25){s+='a'+i/25;i%=25;}s+='a'+i;return s;}
int main(){
	string s;
	map<string,int>m;
	int i=0;
	cout<<"?shiritori"<<endl<<flush;
	for(;i<50;i++){
		cin>>s;
		if(s[0]!='i'||m[s]){cout<<"!OUT"<<endl;return 0;}
		m[s]=1;cout<<'?'<<s[s.size()-1]<<z(i)<<'i'<<endl<<flush;
	}
}