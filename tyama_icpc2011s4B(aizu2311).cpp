#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <functional>
#include <algorithm>
using namespace std;
typedef tuple<int,int,int> tiii;
typedef struct{
	int x;
	int y;
}dir;
vector<dir>D={
	{-1,-1},{0,-1},{1,-1},
	{-1,0},{1,0},
	{-1,1},{0,1},{1,1},
};

const int H=8,W=8;
vector<function<bool(const tiii&,const tiii&)> >sorter={//{num,x,y}
	[](const tiii &a,const tiii &b)->bool{
		if(get<0>(a)<get<0>(b))return true;
		if(get<0>(a)>get<0>(b))return false;
		if(get<2>(a)>get<2>(b))return true;
		if(get<2>(a)<get<2>(b))return false;
		if(get<1>(a)>get<1>(b))return true;
		if(get<1>(a)<get<1>(b))return false;
		return false;
	},
	[](const tiii &a,const tiii &b)->bool{
		if(get<0>(a)<get<0>(b))return true;
		if(get<0>(a)>get<0>(b))return false;
		if(get<2>(a)<get<2>(b))return true;
		if(get<2>(a)>get<2>(b))return false;
		if(get<1>(a)<get<1>(b))return true;
		if(get<1>(a)>get<1>(b))return false;
		return false;
	}
};

int check2(int color,dir&d,int x,int y,vector<string>&m){
	if(x<0||W<=x||y<0||H<=y||m[y][x]=='.')return -1;
	if(m[y][x]==color)return 0;
	int r=check2(color,d,x+d.x,y+d.y,m);
	if(r<0)return r;
	return r+1;
}
int check1(int color,int x,int y,vector<string>&m){
	int R=-1;
	for(auto &d:D){
		int r=check2(color,d,x+d.x,y+d.y,m);
		if(r>0){
			if(R<0)R=0;
			R+=r;
		}
	}
	return R;
}

int fill2(int color,dir&d,int x,int y,vector<string>&m){
	if(x<0||W<=x||y<0||H<=y||m[y][x]=='.')return -1;
	if(m[y][x]==color)return 0;
	int r=fill2(color,d,x+d.x,y+d.y,m);
	if(r<0)return r;
	m[y][x]=color;
	return r+1;
}
void fill1(int color,int x,int y,vector<string>&m){
	for(auto &d:D)fill2(color,d,x+d.x,y+d.y,m);
}

int main(){
	string color="ox";
	vector<string>m(H);
	for(int h=0;h<H;h++)cin>>m[h];
	int turn=0,pass=0;
	for(;;turn^=1){
		vector<tiii>v;
		for(int y=0;y<H;y++)for(int x=0;x<W;x++)if(m[y][x]=='.'){
			int r=check1(color[turn],x,y,m);
			if(r>0)v.push_back(make_tuple(r,x,y));
		}
		if(v.empty()){
			pass++;
			if(pass>1)break;
		}else{
			pass=0;
			sort(v.begin(),v.end(),sorter[turn]);
			tiii &t=*v.rbegin();
			int x=get<1>(t),y=get<2>(t);
			fill1(color[turn],x,y,m);
			m[y][x]=color[turn];
		}
	}
	for(int h=0;h<H;h++)cout<<m[h]<<endl;
	return 0;
}