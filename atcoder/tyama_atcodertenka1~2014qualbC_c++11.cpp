#include <iostream>
#include <string>
#include <vector>
#define MD 3
using namespace std;
typedef struct{
	int y;
	int x;
}dir;
dir D[MD]={
	{-1,0},
	//{1,0},
	{0,-1},
	{0,1},
};
int main(){
	int n;
	cin>>n;
	//if(n>20)return 1; //数万試行以内で解が見つかることを期待する
	vector<string> result(n);
	vector<string> before(n);
	string last_line(n,'.');
	for(int i=0;i<n;i++){
		cin>>result[i];
		before[i]=result[i]; //alloc
	}
	for(int i=0;i<1<<n;i++){
		//先頭行を仮ぎめする
		for(int j=0;j<n;j++)before[0][j]=( i&(1<<j) )?'#':'.';
		for(int l=1;l<n;l++){
			//before[l-1]の隣接黒ますを数える(ただし下は数えない)
			vector<int> black(n);
			for(int k=0;k<n;k++){
				for(auto d:D)if(0<=l-1+d.y&&l-1+d.y<n && 0<=k+d.x&&k+d.x<n && before[l-1+d.y][k+d.x]=='#')black[k]++;
			}
			//before[l]をresult[l-1]と合致するように決定する
			for(int k=0;k<n;k++)before[l][k]=((black[k]+(result[l-1][k]=='#'))&1)?'#':'.';
		}
		//最下行を変換し、チェックする
		vector<int> black(n);
		for(int k=0;k<n;k++){
			for(auto d:D)if(0<=n-1+d.y&&n-1+d.y<n && 0<=k+d.x&&k+d.x<n && before[n-1+d.y][k+d.x]=='#')black[k]++;
		}
		for(int k=0;k<n;k++)last_line[k]=(black[k]&1)?'#':'.';
		if(last_line==result[n-1])break;
	}
	for(int i=0;i<n;i++)cout<<before[i]<<endl;
}