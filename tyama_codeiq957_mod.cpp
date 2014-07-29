#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
typedef pair<unsigned int,unsigned int> slice;
//typedef slice memo_type;
typedef unsigned long long memo_type;

class Solve{
	unordered_map<memo_type,int>memo;
	const string str;
	unsigned int len;

	int compare(const slice &a,const slice &b){
		unsigned int asize=a.second-a.first;
		unsigned int bsize=b.second-b.first;
		if(asize<bsize)return -1;
		if(asize>bsize)return 1;
		for(unsigned int i=0;i<asize;i++){
			int d=str[a.first+i]-str[b.first+i];
			if(d)return d;
		}
		return 0;
	}

	int dfs(const slice &prev){
		if(prev.second==len)return 0;
		if(str[prev.second]=='0')return -1;
		memo_type p=((unsigned long long)prev.first<<32)|prev.second;
		auto memo_it=memo.find(p);
		if(memo_it!=memo.end())return memo_it->second;
		int r=-1;
		for(unsigned int i=prev.second+1;i<=len;i++){
			slice next=make_pair(prev.second,i);
			if(compare(prev,next)<0){
				int x=dfs(next);
				if(x>=0)r=max(r,x+1);
			}
		}
		return memo[p]=r;
	}

public:
	Solve(const string &_str): str(_str){len=str.size();}
	int run(){
		slice next=make_pair(0,0);
		return dfs(next);
	}
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string line;
	for(;getline(cin,line);cout<<Solve(line).run()<<endl<<flush);
}