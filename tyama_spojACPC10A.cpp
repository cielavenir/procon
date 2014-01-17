#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int a,b,c;
	for(;cin>>a>>b>>c,a|b|c;){
		if(c-b==b-a)cout<<"AP "<<c+c-b<<endl;
		else cout<<"GP "<<c*c/b<<endl;
	}
}