//https://qiita.com/Nabetani/items/891d07f4d645ec00ce9a
//http://nabetani.sakura.ne.jp/hena/orde18twintri/
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef struct{
	int x;
	int y;
}dir;
const dir D[]={
	{0,-1},{-1,0},{0,1},{1,0}
};

set<pair<int,int>> get(int X,int Y,int d,int H){
	set<pair<int,int>> se;
	for(int h=0;h<H;h++){
		se.insert({X+D[d].x*h,Y+D[d].y*h});
		for(int i=1;i<=h;i++){
			se.insert({X+D[(d+1)%4].x*i+D[d].x*h,Y+D[(d+1)%4].y*i+D[d].y*h});
			se.insert({X+D[(d+3)%4].x*i+D[d].x*h,Y+D[(d+3)%4].y*i+D[d].y*h});
		}
	}
	return se;
}

int main(){
	const map<char,int> m={
		{'B',0},{'R',1},{'T',2},{'L',3}
	};
	string line;
	for(;getline(cin,line);){
		int x1,y1,h1,x2,y2,h2;
		char d1,d2;
		sscanf(line.c_str(),"%d,%d%c%d/%d,%d%c%d",&x1,&y1,&d1,&h1,&x2,&y2,&d2,&h2);
		//printf("%d %d %c %d %d %d %c %d\n",x1,y1,d1,h1,x2,y2,d2,h2);
		set<pair<int,int>> s1=get(x1,y1,m[d1],h1),s2=get(x2,y2,m[d2],h2),s3;
		set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),inserter(s3,s3.begin()));
		printf("%d\n",s3.size());
		fflush(stdout);
	}
}
