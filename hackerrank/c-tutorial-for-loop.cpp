#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
	vector<string>v={"zero","one","two","three","four","five","six","seven","eight","nine"};
	vector<string>e={"even","odd"};
	int a,b;
	cin>>a>>b;
	for(;a<=b;a++)cout<<(a<10?v[a]:e[a%2])<<endl;
}