#include <iostream>
#include <string>
#include <unordered_map>
#include <cstdlib>
using namespace std;

unordered_map<long long,string>memo;
string dfs(int n,int k){
	if(n>18){
		if(k&1)return dfs(n-2,k/4)+dfs(n-1,k/2);
		return dfs(n-1,k/2)+dfs(n-2,k/4);
	}
	if(n==1&&k==0)return "b";
	if(n==2&&k==0)return "a";
	long long x=((long long)n)<<32|k;
	auto it=memo.find(x);
	if(it!=memo.end())return it->second;
	if(k&1)return memo[x]=dfs(n-2,k/4)+dfs(n-1,k/2);
	return memo[x]=dfs(n-1,k/2)+dfs(n-2,k/4);
}

int main(int argc,char **argv){
	if(argc>2){
		int n=strtol(argv[1],NULL,10);
		int k=strtol(argv[2],NULL,10);
		cout<<dfs(n,k)<<endl;
		return 0;
	}

	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;
	cin>>s;
	if(s=="b")cout<<"1 0"<<endl;
	if(s=="a")cout<<"2 0"<<endl;
	//nは文字数だけから確定できる
	long long K=1;
	int a=1,b=1,c,n=2;
	for(;b<s.size();n++,K*=2){
		c=a+b;
		a=b,b=c;
	}
	//printf("%d %lld\n",n,K); // 22 1048576
	int k=0;
	//if(n==22){
		//最終ケース。コンテスト中はテストケース名が公開じゃなくて色んな意味でよかったですね…。
	//	if(s.substr(0,4)=="abab")k=1048000;
	//}
	for(;k<K;k++){
		if(dfs(n,k)==s){
			cout<<n<<' '<<k<<endl;
			return 0;
		}
	}
}