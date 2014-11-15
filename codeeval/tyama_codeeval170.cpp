#include <iostream>
#include <string>
using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int ma,mi,h;
	string s;
	for(;cin>>ma;){
		mi=0;
		for(;;){
			h=(ma+mi+1)/2;
			cin>>s;
			if(s[0]=='Y'){
				cout<<h<<endl;
				break;
			}else if(s[0]=='H'){
				mi=h+1;
			}else{
				ma=h-1;
			}
		}
	}
}