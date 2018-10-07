#include <iostream>
#include <bitset>
using namespace std;
typedef bitset<32> b32;
int main(){
	unsigned int n,m;
	cin>>n>>m;
	b32 b(n),c(m);
	cout<<(b&c)<<endl;
	cout<<(b|c)<<endl;
	cout<<(b^c)<<endl;
}
