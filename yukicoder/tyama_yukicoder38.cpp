#include <iostream>
#include <string>
using namespace std;
int main(){
	int Kr,Kb,R=0;
	string s;
	cin>>Kr>>Kb>>s;
	for(int i=0;i<1<<10;i++)for(int j=0;j<1<<10;j++){
		string t;
		int k=0,r=0,b=0;
		for(;k<s.size();k++){
			if(s[k]=='R'){
				if(i&(1<<r)){
					if(t.size()>=Kr&&t[t.size()-Kr]=='R')break;
					t+='R';
				}
				r++;
			}else if(s[k]=='B'){
				if(j&(1<<b)){
					if(t.size()>=Kb&&t[t.size()-Kb]=='B')break;
					t+='B';
				}
				b++;
			}else if(s[k]=='W'){
				t+='W';
			}
		}
		if(k==s.size())R=max(R,(int)t.size());
	}
	cout<<R<<endl;
}