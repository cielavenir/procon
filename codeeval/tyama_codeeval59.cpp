#include <iostream>
#include <string>
using namespace std;
string h[]={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
int i=0;
void D(int depth,string &str,string ret){
	if(depth==str.size()){
		if(i>0)cout<<',';
		cout<<ret;
		i++;
	}else{
		for(int k=0;k<h[str[depth]-'0'].size();k++){
			D(depth+1,str,ret+h[str[depth]-'0'][k]);
		}
	}
}
main(){
	string s;
	for(;cin>>s;){
		i=0;
		D(0,s,string(""));
		cout<<endl;
	}
}