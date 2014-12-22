#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	int player;
	cin>>player;
	vector<string>v(8);
	for(int y=0;y<v.size();y++)cin>>v[y];
	for(int y=0;y<v.size();y++)for(int x=0;x<v[y].size();x++)if(v[y][x]=='1'){
		printf("%d %d\n",y,x);
		return 0;
	}
}