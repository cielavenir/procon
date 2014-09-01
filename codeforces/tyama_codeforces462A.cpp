#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef struct{
	int y;
	int x;
}dir;
dir D[4]={
	{-1,0},
	{1,0},
	{0,-1},
	{0,1},
};
int main(){
	int n;
	cin>>n;
	vector<string>v(n);
	for(int i=0;i<n;i++)cin>>v[i];
	for(int i=0;i<n;i++)for(int j=0;j<n;j++){
		int s=0;
		for(auto d:D)if(0<=i+d.y&&i+d.y<n&&0<=j+d.x&&j+d.x<n&&v[i+d.y][j+d.x]=='o')s++;
		if(s%2!=0){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
}