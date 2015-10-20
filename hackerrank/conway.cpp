#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	int cnt=0;
	string player;
	cin>>player;
	vector<string>v(29);
	for(int y=0;y<v.size();y++)cin>>v[y];
	for(int y=0;y<v.size();y++)for(int x=0;x<v[y].size();x++){
		if(v[y][x]=='-')cnt++;
		else cnt--;
		if(cnt==2){
			printf("%d %d\n",y,x);
			return 0;
		}
	}
}