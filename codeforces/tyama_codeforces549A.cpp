#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	int H,W;
	cin>>H>>W;
	vector<string>v(H);
	for(int i=0;i<H;i++){
		cin>>v[i];
		for(int j=0;j<W;j++){
			if(v[i][j]=='f')v[i][j]=1;
			else if(v[i][j]=='a')v[i][j]=2;
			else if(v[i][j]=='c')v[i][j]=4;
			else if(v[i][j]=='e')v[i][j]=8;
			else v[i][j]=-1;
		}
	}
	int R=0;
	for(int i=0;i<H-1;i++)for(int j=0;j<W-1;j++){
		int r=0;
		for(int y=0;y<2;y++)for(int x=0;x<2;x++)if(v[i+y][j+x]>0)r|=v[i+y][j+x];
		if(r==15)R++;
	}
	cout<<R<<endl;
}