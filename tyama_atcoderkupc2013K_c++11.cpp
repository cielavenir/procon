#include <iostream>
#include <map>
#include <string>
#include <algorithm>
//#include <ctime>
using namespace std;
#define M(x,y,z) make_pair((x),make_pair((y),(z)))
typedef map<string,pair<string,string> > mspss;
typedef map<string,map<char,pair<char,string> > >  msmcpcs;
//http://www.kupc.jp/2013/editorial/K.pdf
mspss table1={
	M("A1","B1","B2"),M("A2","B3","B4"),M("A3","B5","B6"),
	M("B1","A1","A2"),M("B2","A3","C1"),M("B3","C2","C3"),M("B4","C4","E1"),M("B5","E2","E3"),M("B6","E4","E5"),
	M("C1","B1","B2"),M("C2","B3","B4"),M("C3","B5","B6"),M("C4","D1","D2"),
	M("D1","C1","C2"),M("D2","C3","C4"),
	M("E1","B1","B2"),M("E2","B3","B4"),M("E3","B5","B6"),M("E4","F1","F2"),M("E5","F3","F4"),
	M("F1","E1","E2"),M("F2","E3","E4"),M("F3","E5","G1"),M("F4","G2","G3"),
	M("G1","F1","F2"),M("G2","F3","F4"),M("G3","H1","H2"),
	M("H1","G1","G2"),M("H2","G3","I1"),
	M("I1","H1","H2"),
};
msmcpcs table2;
string trailing_paths[]={
	"HGFEBA","IHGFEB","BABABC","ABABCD","BABABE","ABABEF","BABEFG","ABEFGH","BEFGHI"
};
int main(){
	string trailing_path=trailing_paths[0];//time(NULL)/86400*86400%9]; //just for fun :p
	string s,t,r;
	int n,i=0;
	cin>>s>>n>>t;
	if(s[0]=='e'){
		// n=8
		// t=10111110
		s=string(1,trailing_path.back())+string(1,'1');
		for(i=0;i<n;i++){
			if(t[i]=='0')r+=(s=table1[s].first)[0];
			else r+=(s=table1[s].second)[0];
		}
		// s=G3
		// r=BABEFGHG
		t=trailing_path.substr(trailing_path.size()-(s[1]-'0'),s[1]-'0');
		// t=EBA
		cout<<t+r<<endl;
	}else{
		mspss::iterator it=table1.begin();
		for(;it!=table1.end();it++){
			table2[it->second.first][it->first[0]]=make_pair('0',it->first);
			table2[it->second.second][it->first[0]]=make_pair('1',it->first);
		}
		// n=11
		// t=EBABABEFGHG
		for(i=0;t[i]!=trailing_path.back();i++);
		n-=i;
		t=t.substr(i);
		s=string(1,t[n-1])+string(1,'1'+i);
		// n=9
		// t=ABABEFGHG
		// s=G3
		for(i=n-2;i>=0;i--){
			r+=table2[s][t[i]].first;
			s=table2[s][t[i]].second;
		}
		reverse(r.begin(),r.end());
		cout<<r<<endl;
	}
}