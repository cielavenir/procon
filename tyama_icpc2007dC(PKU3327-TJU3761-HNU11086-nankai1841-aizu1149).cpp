//tyama_C_fast.cpp
//much faster!

//Perl‚Å‚à‘‚¯‚é‚¯‚Ç‘½•ª‚â‚ç‚È‚¢B

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define hi(x) ((x)>>16)
#define lo(x) ((x)&0xffff)

struct comp{
    bool operator()(const unsigned a, const unsigned b){return hi(a)*lo(a) < hi(b)*lo(b);}
};

inline void solve(int n, int w, int d){
	vector<unsigned> v;
	v.push_back((w<<16)+d);
	while(n--){
		int p, s, state=0;
		scanf("%d %d", &p, &s);
		p--;
		s%=(hi(v.at(p))+lo(v.at(p)));
		
		unsigned x=hi(v.at(p)), y=lo(v.at(p)), _x=0, _y=0;
		while(s--){
			switch(state){
				case 0:{
					_x++;
					if(_x==x)state=1;
					break;
				}
				case 1:{
					_y++;
					/* impossible
					if(_y==y)state=2;
					break;
				}
				case 2:{
					_x--;
					if(_x==0)state=3;
					break;
				}
				case 3:{
					_y--;
					if(_y==0)state=0;
					*/
					break;
				}
			}
		}
		unsigned x1, x2, y1, y2;
		switch(state){
			case 0: /*case 2:*/{
				x1=_x;x2=x-_x;
				y1=y2=y;
				break;
			}
			case 1: /*case 3:*/{
				x1=x2=x;
				y1=_y;y2=y-_y;
				break;
			}
		}
		
		v.erase(v.begin()+p);
		if(x1*y1>x2*y2){
			v.push_back((x2<<16)+y2);
			v.push_back((x1<<16)+y1);
		}else{
			v.push_back((x1<<16)+y1);
			v.push_back((x2<<16)+y2);
		}
	}
	
	sort(v.begin(), v.end(), comp());
	while(v.size()){
		printf("%d", hi(v.at(0))*lo(v.at(0)));
		v.erase(v.begin());
		if(v.size())printf(" "); //‚±‚Ì•Ó‚ÍPerl‚¾‚Æjoin‚ªg‚¦‚é‚¨B
	}
	printf("\n");
}

int main(){
	int n,w,d;
	while(1){
		scanf("%d %d %d",&n,&w,&d);
		if(!n&&!w&&!d)return 0;
		solve(n, w, d);
	}
}