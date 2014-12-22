#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	int player;
	vector<string>v(3);
	cin>>player>>v[0]>>v[1]>>v[2];
	if(v[2][2]=='#'&&v[1][2]!='#')cout<<"RIGHT"<<endl;
	else if(v[0][2]=='#'&&v[0][1]!='#')cout<<"UP"<<endl;
	else if(v[0][0]=='#'&&v[1][0]!='#')cout<<"LEFT"<<endl;
	else if(v[2][0]=='#'&&v[2][1]!='#')cout<<"DOWN"<<endl;
	else cout<<"UP"<<endl;
}