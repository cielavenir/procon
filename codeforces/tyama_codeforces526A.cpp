#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int N;
	string s;
	cin>>N>>s;
	for(int diff=1;(N-1)/diff>=4;diff++)
		for(int start=0;start+4*diff<N;start++){
			int i=0;
			for(;i<=4;i++)if(s[start+diff*i]!='*')break;
			if(i>4){cout<<"yes"<<endl;return 0;}
		}
	cout<<"no"<<endl;
}