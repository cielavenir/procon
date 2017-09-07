//http://nabetani.sakura.ne.jp/hena/ord4tetroid/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> split_int(string &str, const char *delim){
	vector<int> result;
	int cutAt;
	while( (cutAt = str.find_first_of(delim)) != str.npos ){
		if(cutAt > 0){
			result.push_back(strtol(str.substr(0, cutAt).c_str(),NULL,10));
		}
		str = str.substr(cutAt + 1);
	}
	if(str.length() > 0){
		result.push_back(strtol(str.c_str(),NULL,10));
	}
	return result;
}

///
const int D[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
/*
int islandsize(int x,int y,set<pair<int,int> >&area,set<pair<int,int> >&s){
	if(x<0||10<=x||y<0||10<=y||area.find(make_pair(x,y))==area.end()||s.find(make_pair(x,y))!=s.end())return 0;
	s.insert(make_pair(x,y));
	int r=1;
	r+=islandsize(x-1,y,area,s);
	r+=islandsize(x+1,y,area,s);
	r+=islandsize(x,y-1,area,s);
	r+=islandsize(x,y+1,area,s);
	return r;
}
*/
char tetromino(const set<pair<int,int> > &island){ //v is sorted by x, then y
	int i,s;
	set<pair<int,int> >::iterator it=island.begin();
	if(
		island.find(make_pair(it->first+1,it->second))!=island.end()&&
		island.find(make_pair(it->first,it->second+1))!=island.end()&&
		island.find(make_pair(it->first+1,it->second+1))!=island.end()
	)return 'O';
	if((
		island.find(make_pair(it->first+1,it->second))!=island.end()&&
		island.find(make_pair(it->first+2,it->second))!=island.end()&&
		island.find(make_pair(it->first+3,it->second))!=island.end()
	)||(
		island.find(make_pair(it->first,it->second+1))!=island.end()&&
		island.find(make_pair(it->first,it->second+2))!=island.end()&&
		island.find(make_pair(it->first,it->second+3))!=island.end()
	))return 'I';
	for(it=island.begin();it!=island.end();it++){
		vector<int>d;
		for(i=0;i<4;i++)if(island.find(make_pair(it->first+D[i][0],it->second+D[i][1]))!=island.end())d.push_back(i);
		if(d.size()==3)return 'T';
		if(d.size()==2 && abs(d[0]-d[1])!=2){
			//if(d=={0,3})d={3,0};
			if(d[0]==0&&d[1]==3)swap(d[0],d[1]);
			if(island.find(make_pair(it->first+D[ d[0] ][0]*2,it->second+D[ d[0] ][1]*2))!=island.end())return 'L';
			if(island.find(make_pair(it->first+D[ d[1] ][0]*2,it->second+D[ d[1] ][1]*2))!=island.end())return 'L'; //'J';
			if(island.find(make_pair(it->first+D[ d[0] ][0]+D[ (d[0]-1+4)%4 ][0],it->second+D[ d[0] ][1]+D[ (d[0]-1+4)%4 ][1]))!=island.end())return 'S'; //'Z';
			if(island.find(make_pair(it->first+D[ d[1] ][0]+D[ (d[1]+1)%4 ][0],it->second+D[ d[1] ][1]+D[ (d[1]+1)%4 ][1]))!=island.end())return 'S';
		}
	}
	return '-';
}
int main(){
	string line;
	for(;getline(cin,line);){
		vector<int>a=split_int(line,",");
		if(a.size()!=4){cout<<"-"<<endl<<flush;continue;}
		int x,y;
		set<pair<int,int> >area;
		for(int i=0;i<a.size();i++){
			x=a[i]/10,y=a[i]%10;
			area.insert(make_pair(x,y));
		}
		set<pair<int,int> >island=area;
		//if(islandsize(x,y,area,island)!=4){cout<<'-'<<endl<<flush;continue;}
		cout<<tetromino(island)<<endl<<flush;
	}
}
