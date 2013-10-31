//http://qiita.com/Nabetani/items/1de39df381dfeee305ab
//http://nabetani.sakura.ne.jp/hena/ord12aloroturtle/
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
typedef pair<int,int> pii;
string v1[]={
	"ABCDEFGHIJK",
	"LMNOPQRSTUV",
	"WXYZabcdefg",
};
string v2[]={
	"jmpsvy147",
	"ilorux036",
	"hknqtwz25",
};
const int D[4][2]={{1,0},{0,1},{-1,0},{0,-1}}; //RDLU
int main(){
	int x,y,i,d,n;
	map<char,map<int,pair<char,int> > >m;
	for(y=0;y<3/*v1.size()*/;y++){
		for(x=0;x<v1[y].size();x++){
			char c=v1[y][x];
			if(x<v1[y].size()-1)m[c][0]=make_pair(v1[y][x+1],0);
			if(y<3/*v1.size()*/-1)m[c][1]=make_pair(v1[y+1][x],1);
			if(x>0)m[c][2]=make_pair(v1[y][x-1],2);
			if(y>0)m[c][3]=make_pair(v1[y-1][x],3);
		}
	}
	for(y=0;y<3/*v2.size()*/;y++){
		for(x=0;x<v2[y].size();x++){
			char c=v2[y][x];
			if(x<v1[y].size()-1)m[c][0]=make_pair(v2[y][x+1],0);
			if(y<3/*v1.size()*/-1)m[c][1]=make_pair(v2[y+1][x],1);
			if(x>0)m[c][2]=make_pair(v2[y][x-1],2);
			if(y>0)m[c][3]=make_pair(v2[y-1][x],3);
		}
	}
	m['W'][1]=make_pair('h',0);
	m['X'][1]=make_pair('i',0);
	m['Y'][1]=make_pair('j',0);
	m['h'][2]=make_pair('W',3);
	m['i'][2]=make_pair('X',3);
	m['j'][2]=make_pair('Y',3);
	m['e'][1]=make_pair('7',2);
	m['f'][1]=make_pair('6',2);
	m['g'][1]=make_pair('5',2);
	m['7'][0]=make_pair('e',3);
	m['6'][0]=make_pair('f',3);
	m['5'][0]=make_pair('g',3);
	string line;
	for(;getline(cin,line);){
		char cur='A',nxt;
		d=0;
		cout<<cur;
		for(i=0;i<line.size();i++){
			if(line[i]=='L')d=(d+3)%4;
			else if(line[i]=='R')d=(d+1)%4;
			else{
				n=0;
				if('1'<=line[i]&&line[i]<='9')n=line[i]-'0';
				if('a'<=line[i]&&line[i]<='f')n=line[i]-'a'+10;
				if(!n)break;
				for(;n;n--){
					if(m[cur].find(d)==m[cur].end()){cout<<'?';break;}
					nxt=m[cur][d].first;
					d=m[cur][d].second;
					cur=nxt;
					cout<<cur;
				}
				if(n)break;
			}
		}
		cout<<endl<<flush;
	}
}