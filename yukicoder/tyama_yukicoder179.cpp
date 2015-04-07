#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;
int main(){
	int h,w;
	cin>>h>>w;
	vector<string>m0(h);
	for(int i=0;i<h;i++)cin>>m0[i];
	for(int dx=0;dx<w;dx++)for(int dy=-h;dy<h;dy++)if(dx||dy){
		auto m=m0;
		int f=0;
		for(int x=0;x<w;x++)for(int y=0;y<h;y++){
			if(m[y][x]=='#'){
				f|=1;
				if(x+dx<0||w<=x+dx || y+dy<0||h<=y+dy || m[y+dy][x+dx]=='.')f|=2;
				else m[y][x]=m[y+dy][x+dx]='.';
			}
		}
		if(f==1){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
}