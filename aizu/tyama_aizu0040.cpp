#include <string>
#include <iostream>
using namespace std;
int main(){
	int N,a,b,i,c;
	string s,t;
	for(cin>>N,getline(cin,s);N--;){
		getline(cin,s);
		for(a=1;a<26;a++){
			if(a%2==0||a%13==0)continue;
			for(b=0;b<26;b++){
				for(t=s,i=0;i<t.length();i++){
					if(t[i]<'a'||'z'<t[i])continue;
					c=t[i]-'a'+b;for(;c%a;)c+=26;
					t[i]=c/a%26+'a';
				}
				if(t.find("this")!=-1||t.find("that")!=-1){cout<<t<<endl;goto n;}
			}
		}	
	n:;}
}