#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
using namespace std;
typedef pair<int,int>pii;

int H,W;
vector<string>m;
map<pii,int>memo;
int chk(int h,int w){
	if(H<=h||W<=w||m[h][w]=='#')return 1;
	pii p=make_pair(h,w);
	if(memo.find(p)!=memo.end())return memo[p];
	return memo[p]=!chk(h,w+1)||!chk(h+1,w+1)||!chk(h+1,w);
}

int main(){
	cin>>H>>W;
	m.resize(H);
	for(int i=0;i<H;i++)cin>>m[i];
	puts(chk(0,0)?"First":"Second");
}