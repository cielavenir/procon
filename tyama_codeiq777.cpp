#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdio>
using namespace std;
int chain(vector<int> a){ //a is copied
	int r=0;
	for(;a[0]!=1;r++)reverse(a.begin(),a.begin()+a[0]);
	return r;
}
int main(){
	vector<int> v(9),ret;
	iota(v.begin(),v.end(),1);
	int m=0;
	do{
		int n=chain(v);
		if(m<n)m=n,ret=v;
	}while(next_permutation(v.begin(),v.end()));
	for(int i=0;i<ret.size();i++)printf("%d",ret[i]); // 615972834
	puts("");
}