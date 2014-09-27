#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> v={
"-**----*--***--***---*---****--**--****--**---**--",
"*--*--**-----*----*-*--*-*----*-------*-*--*-*--*-",
"*--*---*---**---**--****-***--***----*---**---***-",
"*--*---*--*-------*----*----*-*--*--*---*--*----*-",
"-**---***-****-***-----*-***---**---*----**---**--",
"--------------------------------------------------",
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string line;
	for(;getline(cin,line);){
		for(int i=line.size()-1;i>=0;i--)if(line[i]<'0'||'9'<line[i])line.erase(line.begin()+i);
		for(int j=0;j<v.size();j++){
			for(int i=0;i<line.size();i++){
				for(int k=0;k<5;k++)putchar(v[j][(line[i]-'0')*5+k]);
			}
			puts("");
		}
	}
}