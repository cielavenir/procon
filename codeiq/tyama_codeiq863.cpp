#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef pair<string,pair<int,int> > pspii;
int main(){
	vector<pspii> data;
	vector<string> ma;
	int i1,i2,i3,i4;
	string s,t;
	for(;cin>>s>>t;){
		sscanf(t.c_str(),"%d/%d-%d/%d",&i1,&i2,&i3,&i4);
		data.push_back(make_pair(s,make_pair(i1*100+i2,i3*100+i4)));
	}
	sort(data.begin(),data.end(),[](pspii &a,pspii &b){return a.second.second<b.second.second;});
	int f=0;
	for(int i=0;i<data.size();i++){
		if(data[i].second.first>f){ //終端は閉区間。開区間なら>=になる。
			ma.push_back(data[i].first);
			f=data[i].second.second;
		}
	}
	sort(ma.begin(),ma.end()); // ※※※日時順ではなく国名順※※※
	printf("%d",ma.size());
	for(int i=0;i<ma.size();i++)printf(" %s",ma[i].c_str());
	puts("");
}
/*
62 Afghanistan Angola Antarctica Austria Azerbaijan Bahamas Barbados Belarus Botswana Burundi Canada China Cyprus Denmark Dominica Ecuador Eritrea Ethiopia Finland Georgia Germany Ghana Greece Jordan Kiribati Kuwait Kyrgyzstan Libya Liechtenstein Macao Malawi Malaysia Martinique Montenegro Montserrat Myanmar Namibia Narnia Nepal Niger Nigeria Oman Poland Portugal Romania Rwanda Samoa Senegal Serbia Seychelles Slovakia Slovenia Somalia Sudan Switzerland Tajikistan Tokelau Turkey Uganda Ukraine Zambia Zimbabwe
ENV:C++11
POINT:区間スケジューリング
spaghetti sourceを適当に変更して使ったので、特にコメントはありません…。
１回目の投稿後、あまりにも結城先生がケアレスミスについて語るのでおかしいと思ったら、日時順で出力してしまっていました。国名順で出力するように修正して再提出。危なかった…。
*/