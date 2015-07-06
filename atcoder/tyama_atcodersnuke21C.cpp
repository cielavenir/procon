#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int N;
	cin>>N;
	vector<int>v(N);
	vector<int>dp(1<<12);
	for(int i=0;i<N;i++){
		string s;
		cin>>s;
		int val=0;
		for(int j=0;j<s.size();j++){
			if(s[j]=='o')val|=1<<j;
		}
		v[i]=val;
	}
	for(int i=(1<<12)-1;i>=0;i--)for(int j=0;j<N;j++)if((i|v[j])>i)dp[i]=max(dp[i],dp[i|v[j]]+1);
	printf("%d\n",dp[0]);
}