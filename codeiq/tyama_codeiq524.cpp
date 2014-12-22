#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;

vector<string> split(string &str, const char *delim){
	vector<string> result;
	int cutAt;
	while( (cutAt = str.find_first_of(delim)) != str.npos ){
		if(cutAt > 0){
			result.push_back(str.substr(0, cutAt));
		}
		str = str.substr(cutAt + 1);
	}
	if(str.length() > 0){
		result.push_back(str);
	}
	return result;
}
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
int islandsize(int x,int y,set<pair<int,int> >&area,set<pair<int,int> >&s){
	if(area.find(make_pair(x,y))==area.end()||s.find(make_pair(x,y))!=s.end())return 0;
	s.insert(make_pair(x,y));
	int r=1;
	r+=islandsize(x-1,y,area,s);
	r+=islandsize(x+1,y,area,s);
	r+=islandsize(x,y-1,area,s);
	r+=islandsize(x,y+1,area,s);
	return r;
}
string tetromino(set<pair<int,int> > &island){ //v is sorted by x, then y
	int i,s;
	set<pair<int,int> >::iterator it=island.begin();
	if(
		island.find(make_pair(it->first+1,it->second))!=island.end()&&
		island.find(make_pair(it->first,it->second+1))!=island.end()&&
		island.find(make_pair(it->first+1,it->second+1))!=island.end()
	)return "O";
	if((
		island.find(make_pair(it->first+1,it->second))!=island.end()&&
		island.find(make_pair(it->first+2,it->second))!=island.end()&&
		island.find(make_pair(it->first+3,it->second))!=island.end()
	)||(
		island.find(make_pair(it->first,it->second+1))!=island.end()&&
		island.find(make_pair(it->first,it->second+2))!=island.end()&&
		island.find(make_pair(it->first,it->second+3))!=island.end()
	))return "I";
	for(it=island.begin();it!=island.end();it++){
		vector<int>d;
		for(i=0;i<4;i++)if(island.find(make_pair(it->first+D[i][0],it->second+D[i][1]))!=island.end())d.push_back(i);
		if(d.size()==3)return "T";
		else if(d.size()==2&&(
			island.find(make_pair(it->first+D[ d[0] ][0]*2,it->second+D[ d[0] ][1]*2))!=island.end()||
			island.find(make_pair(it->first+D[ d[1] ][0]*2,it->second+D[ d[1] ][1]*2))!=island.end()
		))return "L";
	}
	return "S";
}
int main(){
#ifdef TEST
	string _call="74,72,90,23,68,36,35,41,67,18,1,89,39,80,47,10,45,40,26,91,6,98,73,53,44,24,52,63,46,59,28,92,13,94,66,49,3,87,64,4,88,76,96,9,29,85,42,82,25,51,86,19,83,14,77,78,58,62,81,22,93,15,2,20,33,57,37,48,38,34,79,17,65,60,11,31,27,5,69,32,95,99,50,16,70,75,12,7,56,21,97,30,8,61,55,84,54,71,43";
#else
	string _call;
	getline(cin,_call);
#endif
	vector<int> call=split_int(_call,",");

	map<string,int> total;
	string line;
	for(;getline(cin,line);){
		string result="-";
		map<int,pair<int,int> >card;
		vector<string>a=split(line,"/");
		int y=0,x;
		for(;y<a.size();y++){
			vector<int>b=split_int(a[y],",");
			for(x=0;x<b.size();x++)card[b[x]]=make_pair(x,y);
		}
		set<pair<int,int> >area;
		for(int i=0;i<call.size();i++){
			if(card.find(call[i])==card.end())continue;
			pair<int,int> coor=card[call[i]];
			area.insert(coor);
			set<pair<int,int> >island;
			if(islandsize(coor.first,coor.second,area,island)!=4)continue;
			result=tetromino(island);
			break;
		}
		if(result!="-")total[result]++;
#ifdef TEST
		cout<<result<<endl<<flush;
#endif
	}
#ifndef TEST
	cout<<"I:"<<total["I"]<<",L:"<<total["L"]<<",O:"<<total["O"]<<",S:"<<total["S"]<<",T:"<<total["T"]<<endl;
#endif
}
/*
・前回のような過ちを犯さぬために、「横へな採点プログラムVersion2」で事前に採点した。結果の数値が揃っているので今回は大丈夫でしょう。。
・横へな第４回「テトロミノ認識」問題はまだ解いていなかったが、この問題を解くために解いた。そしてtetromino()を流用した。
・tetromino()内の処理はかなり泥臭くはあるが、islandをvectorではなくsetにすることで効率化を図っている。
・前回指摘があったので、グローバル変数は使わないようにした(Dはconstにしてある)。
*/