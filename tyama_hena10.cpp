//http://qiita.com/Nabetani/items/55641767510c2f9f235f
//http://nabetani.sakura.ne.jp/hena/ord10haniwa/
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<pair<int,int>,char>M={
	{{0,0},'A'},

	{{0,-1},'B'},
	{{1,-1},'C'},
	{{1,0},'D'},
	{{0,1},'E'},
	{{-1,1},'F'},
	{{-1,0},'G'},

	{{0,-2},'H'},
	{{1,-2},'I'},
	{{2,-2},'J'},
	{{2,-1},'K'},
	{{2,0},'L'},
	{{1,1},'M'},
	{{0,2},'N'},
	{{-1,2},'O'},
	{{-2,2},'P'},
	{{-2,1},'Q'},
	{{-2,0},'R'},
	{{-1,-1},'S'},

	{{0,-3},'T'},
	{{1,-3},'U'},
	{{2,-3},'V'},
	{{3,-3},'W'},
	{{3,-2},'X'},
	{{3,-1},'Y'},
	{{3,0},'Z'},
	{{2,1},'a'},
	{{1,2},'b'},
	{{0,3},'c'},
	{{-1,3},'d'},
	{{-2,3},'e'},
	{{-3,3},'f'},
	{{-3,2},'g'},
	{{-3,1},'h'},
	{{-3,0},'i'},
	{{-2,-1},'j'},
	{{-1,-2},'k'},
};

const int D[6][2]={{0,-1},{1,-1},{1,0},{0,1},{-1,1},{-1,0}};
int main(){
	string line;
	for(;getline(cin,line);){
		int i=0;
		pair<int,int>q,p=make_pair(0,0);
		cout<<'A';
		for(;i<line.size();i++){
			q=make_pair(p.first+D[line[i]-'0'][0],p.second+D[line[i]-'0'][1]);
			if(M.find(q)==M.end())cout<<'!';
			else{cout<<M[q];p=q;}
		}
		cout<<endl<<flush;
	}
}