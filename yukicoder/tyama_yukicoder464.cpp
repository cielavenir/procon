#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

char s[5001];
bool flg[5000][5000];
bool palindrome(int i,int j){
#if 0
	for(;i<j;i++,j--)if(s[i]!=s[j])return false;
	return true;
#else
	return flg[i][j];
#endif
}

int main(){
	long long r=0;
	scanf("%s",s);
	int len=strlen(s);

	for(int i=0;i<len;i++){
		//odd
		for(int j=0;0<=i-j&&i+j<len;j++){
			if(s[i-j]!=s[i+j])break;
			flg[i-j][i+j]=true;
		}
		//even
		for(int j=0;0<=i-j&&i+j+1<len;j++){
			if(s[i-j]!=s[i+j+1])break;
			flg[i-j][i+j+1]=true;
		}
	}

	vector<int>head,tail;
	for(int i=0;i<len;i++)if(palindrome(0,i))head.push_back(i);
	for(int i=0;i<len;i++)if(palindrome(i,len-1))tail.push_back(i);
	for(auto &e:head){
		for(int i=e+1;i<len;i++)
			if(palindrome(e+1,i))
				r+=distance(lower_bound(tail.begin(),tail.end(),i+2),tail.end());
	}
	printf("%lld\n",r);
	return 0;
}
