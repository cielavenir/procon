#include <fstream>
#include <string>
#include <stack>
#include <map>
using namespace std;
int main(int argc, char **argv){
	map<char,int>I,O;
	I['(']=1,I['{']=2,I['[']=3;
	O[')']=1,O['}']=2,O[']']=3;
	//ifstream fin(argv[1]);
	string s;
	for(;getline(cin,s);){
		int i=0;
		stack<int>st;
		for(;i<s.length();i++){
			if(I[s[i]])st.push(I[s[i]]);
			else{
				if(O[s[i]]!=st.top())break;
				st.pop();
			}
		}
		puts(i==s.length()&&st.empty()?"True":"False");
	}
}