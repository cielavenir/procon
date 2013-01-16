#include <map>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;
int m[29][29];
main(){
	string s,t;
	int h,w,i,j,x,y,X,Y;
	for(;cin>>h>>w,h;cout<<s<<endl){
		vector<string>v;
		for(i=0;i<h;i++)cin>>s,v.push_back(s);
		s="0";
		map<string,int>M;
		for(i=0;i<h;i++)for(j=0;j<w;j++)for(x=-1;x<=1;x++)for(y=-1;y<=1;y++)if(x||y){
			memset(m,0,sizeof(m));
			Y=i,X=j;
			t=v[Y][X],m[Y][X]=1;X=(X+x+w)%w,Y=(Y+y+h)%h;
			for(;!m[Y][X];X=(X+x+w)%w,Y=(Y+y+h)%h){
				t+=v[Y][X],m[Y][X]=1;
				if(++M[t]>1 && (s.size()<t.size()||(s.size()==t.size()&&s>t)))s=t;
			}
		}
	}
}