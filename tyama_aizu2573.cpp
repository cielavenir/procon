#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int ret;
vector<int>vx,vy;
void dfs(int d,int x,int y,int n){
	if(ret<n)ret=n;
	if(0<d&&x<vx.size())dfs(d-1,x+1,y,n+vx[x]);
	if(1<d&&y<vy.size())dfs(d-2,x,y+1,n+vy[y]);
}
int main(){
	int d,x,y,n;
	string s;

	cin>>d;
	for(cin>>x;x--;){
		cin>>s>>n;
		if(s=="D")vx.push_back(n);
	}
	for(cin>>y;y--;){
		cin>>s>>n;
		if(s=="DD")vy.push_back(n);
	}
	sort(vx.begin(),vx.end(),greater<int>());
	sort(vy.begin(),vy.end(),greater<int>());
/*
	//greedy
	for(x=y=n=0;;){
		if(d>0 && x<vx.size()){
			if(d>1 && y<vy.size() && vx[x]<vy[y]){
				d-=2;
				if(x<vx.size()-1 && vx[x]+vx[x+1]>=vy[y]){
					n+=vx[x]+vx[x+1];
					x+=2;
				}else{
					n+=vy[y];
					y++;
				}
			}else{
				d-=1;
				n+=vx[x];
				x++;
			}
		}else if(d>1 && y<vy.size()){
			d-=2;
			n+=vy[y];
			y++;
		}else{
			break;
		}
	}
	cout<<n<<endl;
*/
	dfs(d,0,0,0);
	cout<<ret<<endl;
}