#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define getnum(i) '2'<=(i) && (i)<='9' ? (i)-'0' : (i)=='1' ? 10 : (i)=='J' ? 11 : (i)=='Q' ? 12 : (i)=='K' ? 13 : 1 //A

//http://shnya.jp/blog/?p=195
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
int a[7];
int main(){
	int rank,i;
	string s;
	for(;getline(cin,s);){
		vector<string>_v=split(s,",");
		vector<pair<int,char> >v; //number, suit
		for(i=0;i<_v.size();i++)v.push_back(make_pair(getnum(_v[i][1]),_v[i][0]));
		sort(v.begin(),v.end()); //sort by number
		if(
			(v[0].first==v[1].first&&v[1].first==v[2].first&&v[2].first==v[3].first && v[4].first==v[5].first) ||
			(v[0].first==v[1].first && v[2].first==v[3].first&&v[3].first==v[4].first&&v[4].first==v[5].first)
		){
			rank=0;
		}else if(
			v[0].first==v[1].first&&v[1].first==v[2].first && v[3].first==v[4].first&&v[4].first==v[5].first
		){
			rank=1;
			rank+=(v[0].second==v[3].second && v[1].second==v[4].second && v[2].second==v[5].second)?0:1;
		}else if(
			v[0].first==v[1].first && v[2].first==v[3].first && v[4].first==v[5].first
		){
			rank=3;
			rank+=(v[0].second==v[2].second&&v[2].second==v[4].second && v[1].second==v[3].second&&v[3].second==v[5].second)?0:1; //ghaa!
			rank+=(
				(v[0].first==1&&v[2].first==12&&v[4].first==13) ||
				(v[4].first-v[2].first==1 && v[2].first-v[0].first==1)
			)?0:2;
		}else rank=7;
		if(rank<7)a[rank]++;
	}
	printf("An:%d,sDT:%d,DT:%d,scTP:%d,cTP:%d,sTP:%d,TP:%d\n",a[0],a[1],a[2],a[3],a[4],a[5],a[6]);
}