#include <iostream>
#include <string>
#include <bitset>
#include <vector>
#define mN 1000
using namespace std;
int main(){
	string line;
	int N,M,r=0,n=0;
	cin>>N>>M;
	vector<bitset<mN> >v;
	for(int i=0;i<N;i++){
		cin>>line;
		v.push_back(bitset<mN>(line));
	}
	for(int i=0;i<N-1;i++)for(int j=i+1;j<N;j++){
		bitset<mN>b=v[i]|v[j];
		if(b.count()>r)r=b.count(),n=0;
		if(b.count()==r)n++;
	}
	cout<<r<<endl;
	cout<<n<<endl;
}