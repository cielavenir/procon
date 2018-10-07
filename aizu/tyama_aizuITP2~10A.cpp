#include <iostream>
#include <bitset>
using namespace std;
typedef bitset<32> b32;
int main(){
	unsigned int n;
	cin>>n;
	b32 b(n);
	cout<<b<<endl;
	cout<<~b<<endl;
	cout<<(b<<1)<<endl;
	cout<<(b>>1)<<endl;
}
