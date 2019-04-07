//http://nabetani.sakura.ne.jp/hena/orde32rects/
//https://qiita.com/Nabetani/items/bd16f3fa1d9e4d0d60ae

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <future>
#include <cstdio>
using namespace std;

const int B=36;

set<int> split_int(string &str, const char *delim){
	set<int> result;
	int cutAt;
	while( (cutAt = str.find_first_of(delim)) != str.npos ){
		if(cutAt > 0){
			result.insert(strtol(str.substr(0, cutAt).c_str(),NULL,B));
		}
		str = str.substr(cutAt + 1);
	}
	if(str.length() > 0){
		result.insert(strtol(str.c_str(),NULL,B));
	}
	return result;
}

int f(const vector<vector<int>> &v,int y1,int x1,int y2,int x2){
	for(int i=x1;i<=x2;i++)if(!v[y1][i])return 0;
	for(int i=x1;i<=x2;i++)if(!v[y2][i])return 0;
	for(int i=y1;i<=y2;i++)if(!v[i][x1])return 0;
	for(int i=y1;i<=y2;i++)if(!v[i][x2])return 0;
	for(int j=y1+1;j<=y2-1;j++)for(int i=x1+1;i<=x2-1;i++)if(v[j][i])return 0;
	//printf("%d %d %d %d %d\n",x1/2,y1/2,x2/2,y2/2,(y2-y1)/2*(x2-x1)/2);
	return (y2-y1)/2*(x2-x1)/2;
}

int main(){
	string line;
	for(;getline(cin,line);){
		vector<vector<int>>v(2*B-1);
		for(auto &e:v)e.resize(2*B-1);
		set<int>a=split_int(line,"/");
		for(auto &e:a){
			int l=e/B/B/B*2;
			int t=e/B/B%B*2;
			int r=e/B%B*2;
			int d=e%B*2;
			for(int i=l;i<=r;i++)v[t][i]=1;
			for(int i=l;i<=r;i++)v[d][i]=1;
			for(int i=t;i<=d;i++)v[i][l]=1;
			for(int i=t;i<=d;i++)v[i][r]=1;
		}

		// 全部のスレッドに均等に処理を与えられない以上、スレッド数は適当に増やしたほうが良いか？
		int num_threads=thread::hardware_concurrency(); //*2;
		auto g=[&](int start)->multiset<int>{
			multiset<int> se;
			for(int y1=start*2;y1<=2*B-4;y1+=2*num_threads)for(int y2=y1+2;y2<=2*B-2;y2+=2){
				for(int x1=0;x1<=2*B-4;x1+=2)for(int x2=x1+2;x2<=2*B-2;x2+=2){
					if(v[y1][x1] && v[y1+1][x1] && v[y1][x1+1] && v[y2][x2] && v[y2-1][x2] && v[y2][x2-1]){
						int r=f(v,y1,x1,y2,x2);if(r)se.insert(r);
					}
				}
			}
			return se;
		};

		vector<future<multiset<int>>>task;
		for(int i=1;i<num_threads;i++)task.push_back(async(launch::async,g,i));
		multiset<int>se=g(0);
		for(auto &t:task)for(auto &e:t.get())se.insert(e);
		bool first=true;
		for(auto &e:se){
			if(!first)putchar(',');
			first=false;
			printf("%d",e);
		}
		puts("");
		fflush(stdout);
	}
}
