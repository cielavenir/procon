#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

vector<string> split(string &str, const char *delim){
	vector<string> result;
	int cutAt;
	while( (cutAt = str.find_first_of(delim)) != str.npos ){
		//if(cutAt > 0){
			result.push_back(str.substr(0, cutAt));
		//}
		str = str.substr(cutAt + 1);
	}
	//if(str.length() > 0){
		result.push_back(str);
	//}
	return result;
}
int main(){
map<string,char> m;
m[""]=32;
m[".-.-."]=43;
m["-..-."]=47;
m["-----"]=48;
m[".----"]=49;
m["..---"]=50;
m["...--"]=51;
m["....-"]=52;
m["....."]=53;
m["-...."]=54;
m["--..."]=55;
m["---.."]=56;
m["----."]=57;
m["-...-"]=61;
m[".-"]=65;
m[".-.-"]=65;
m["-..."]=66;
m["-.-."]=67;
m["-.."]=68;
m["."]=69;
m["..-."]=70;
m["--."]=71;
m["...."]=72;
m[".."]=73;
m[".---"]=74;
m["-.-"]=75;
m[".-.."]=76;
m["--"]=77;
m["-."]=78;
m["---"]=79;
m[".--."]=80;
m["--.-"]=81;
m[".-."]=82;
m["..."]=83;
m["-"]=84;
m["..-"]=85;
m["...-"]=86;
m[".--"]=87;
m["-..-"]=88;
m["-.--"]=89;
m["--.."]=90;

	string line;
	int i;
	for(;getline(cin,line);cout<<endl){
		vector<string>a=split(line," ");
		for(i=0;i<a.size();i++){
			cout<<m[a[i]];
		}
	}
}