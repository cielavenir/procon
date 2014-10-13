#include <iostream>
#include <string>
using namespace std;
int main(){
	int n,i;
	cin>>n;
	string pre,cur;
	cin>>pre;
	for(;cin>>cur;){
		if(cur=="----"){
			if(pre=="----"){
				cout<<"being"<<endl;
			}else if(pre=="has"||pre=="have"){
				cout<<"been"<<endl;
			}else if(pre[pre.size()-1]=='s'){
				cout<<"were"<<endl;
			}else{
				cout<<"was"<<endl;
			}
		}
		pre=cur;
	}
}