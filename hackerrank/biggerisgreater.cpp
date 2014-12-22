#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	int n;
	string s;
	for(cin>>n;n--;){
		cin>>s;
		if(next_permutation(s.begin(),s.end()))cout<<s<<endl;
		else cout<<"no answer"<<endl;
	}
}