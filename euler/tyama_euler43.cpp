#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdio>
using namespace std;

int main(){
	vector<int> A={2,3,5,7,11,13,17};
	int n;
	long long r=0,x;
	scanf("%d",&n);
	string s(n+1,'0');
	iota(s.begin(),s.end(),'0');
	do{
		//if(s[0]=='0')continue;
		int i=1;
		for(;i<s.size()-2;i++){
			sscanf(s.substr(i,3).c_str(),"%lld",&x);
			if(x%A[i-1])break;
		}
		if(i==s.size()-2){
			sscanf(s.c_str(),"%lld",&x);
			r+=x;
		}
	}while(next_permutation(s.begin(),s.end()));
	printf("%lld\n",r);
}
// 9