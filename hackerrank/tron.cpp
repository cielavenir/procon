#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cstdlib>
#include <unistd.h>
using namespace std;
int D[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
string moves[]={"UP","LEFT","DOWN","RIGHT"};
vector<string> board;
int islandsize(int x,int y,set<pair<int,int> >&s){
	if(board[y][x]!='-'||s.find(make_pair(x,y))!=s.end())return 0;
	s.insert(make_pair(x,y));
	int r=1;
	r+=islandsize(x-1,y,s);
	r+=islandsize(x+1,y,s);
	r+=islandsize(x,y-1,s);
	r+=islandsize(x,y+1,s);
	return r;
}

int main() {
	string s;
	//srand(time(NULL)^(getpid()<<16));
	vector<int> valid_moves;
	char player;
	int x,y,X,Y,m,M,r,i;
	int i_x, i_y, o_x, o_y;
	{
		cin>>player>>i_y>>i_x>>o_y>>o_x;
		if(player == 'r'){
			x = i_x;
			y = i_y;
		}else{
			x = o_x;o_x = i_x;
			y = o_y;o_y = i_y;
		}
	}
	for(;cin>>s;)board.push_back(s);
	for(i=0;i<4;i++){
		Y=o_y+D[i][0];
		X=o_x+D[i][1];
		board[Y][X]='*';
	}
	for(r=m=i=0;i<4;i++){
		set<pair<int,int> >s;
		Y=y+D[i][0];
		X=x+D[i][1];
		M=islandsize(X,Y,s);
		if(m<M)m=M,r=i;
	}
	cout<<moves[r]<<endl;
}