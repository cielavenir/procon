#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
const int D[4][2]={ //Right,Up,Left,Down
	{0,1},
	{-1,0},
	{0,-1},
	{1,0},
};
string di="RULD";
int main(){
	int N,K,H,W,T;
	cin>>N>>K>>H>>W>>T;
	for(int i=0;i<K;i++)cout<<i<<(i==K-1 ? '\n' : ' ');
	for(int t=0,l=1,q=0,x=0;t<T;t++){
		cout<<di[x];
		q++;
		if(q==l){
			q=0;
			x++;
			if(x==4){
				x=0;
				l++;
			}
		}
	}
	cout<<endl;
}
