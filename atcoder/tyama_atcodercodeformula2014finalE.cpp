#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s;
vector<int>fib;
vector<long long>power2;
int search(int level,int start){
	if(level==3){
		if(s.substr(start,fib[level])=="ab")return 0;
		if(s.substr(start,fib[level])=="ba")return 1;
		return -1;
	}
	int x;
	if(s.substr(start,fib[level-2])==s.substr(start+fib[level-2],fib[level-2])){
		x=search(level-1,start+fib[level-2]);
		if(x>=0)return x*2+1;
	}
	if(s.substr(start+fib[level-3],fib[level-2])==s.substr(start+fib[level-3]+fib[level-2],fib[level-2])){
		x=search(level-1,start);
		if(x>=0)return x*2;
	}
	if(s.substr(start,fib[level-2])==s.substr(start+fib[level-3]+fib[level-2],fib[level-2])){
		x=search(level-1,start);
		if(x>=0)return x*2;
		x=search(level-1,start+fib[level-2]);
		if(x>=0)return x*2+1;
	}
	return -1;
}

int main(){
	{
		fib.push_back(0);
		fib.push_back(1);
		fib.push_back(1);
		power2.push_back(0);
		power2.push_back(0);
		power2.push_back(1);
		long long K=1;
		int a=1,b=1,c,n=3;
		for(;n<=22;n++){
			c=a+b;
			a=b,b=c;
			fib.push_back(b);
			power2.push_back(K*=2);
		}
	}

	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>s;
	if(s=="b"){
		cout<<"1 0"<<endl;
	}else if(s=="a"){
		cout<<"2 0"<<endl;
	}else{
		int level=0;
		for(;level<fib.size();level++)if(fib[level]==s.size())break;
		cout<<level<<' '<<search(level,0)<<endl;
	}
}