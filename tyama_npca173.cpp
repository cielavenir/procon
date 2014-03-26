#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
	int w,h,i,j,r,R=0;
	cin>>w>>h;
	vector<string>v(h);
	for(i=0;i<h;i++)cin>>v[i];
	for(i=0;i<h;R=R>r?R:r,i++)for(r=j=0;j<w;j++)r+=v[i][j]=='.';
	for(j=0;j<w;R=R>r?R:r,j++)for(r=i=0;i<h;i++)r+=v[i][j]=='.';
	cout<<R<<endl;
}