#include <iostream>
#include <string>
#include <set>
using namespace std;
set<pair<char,char> >s={
	{'A','B'},{'A','D'},
	{'B','A'},{'B','C'},{'B','E'},
	{'C','B'},{'C','F'},
	{'D','A'},{'D','E'},{'D','G'},
	{'E','B'},{'E','D'},{'E','F'},{'E','H'},
	{'F','C'},{'F','E'},{'F','I'},
	{'G','D'},{'G','H'},
	{'H','E'},{'H','G'},{'H','I'},
	{'I','F'},{'I','H'},
};
int main(){
	int i;
	string str;
	for(;cin>>str;){
		for(i=1;i<str.size();i++)if(s.find(make_pair(str[i-1],str[i]))==s.end())break;
		if(i==str.size())cout<<str<<endl;
	}
}