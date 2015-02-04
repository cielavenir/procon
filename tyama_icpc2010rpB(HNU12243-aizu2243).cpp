#include <iostream>
#include <string>
using namespace std;
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;
	int m[2];
	for(;cin>>s,s!="#";){
		m[0]=m[1]=0;
		for(int i=1;i<s.size();i++){
			if((s[i]-'1')%3>(s[i-1]-'1')%3){
				m[0]=min(m[0]+1,m[1]);
				m[1]=1<<30;
			}else if((s[i]-'1')%3<(s[i-1]-'1')%3){
				m[1]=min(m[0],m[1]+1);
				m[0]=1<<30;
			}else{
				m[1]^=m[0],m[0]^=m[1],m[1]^=m[0];
			}
		}
		cout<<min(m[0],m[1])<<endl;
	}
}