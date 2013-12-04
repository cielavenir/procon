#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	string line;
	int r,i,c;
	for(;cin>>line,line!="0";cout<<r<<endl){
		vector<int>v(11);
		for(r=i=0;i<line.size();i++){
			c=line[i]-'0';
			reverse(v.begin()+1,v.end());
			rotate(v.begin(),v.begin()+(11-c),v.end());
			r+=v[0];
			if(c)v[c]++;
		}
	}
}
/*
R言語で
(0:10*10)%%11
を実行すると
0 10  9  8  7  6  5  4  3  2  1
が得られる。すなわち第1要素から末端を逆転すれば良い。
また、
(0:10*10+1)%%11
を実行すると
1  0 10  9  8  7  6  5  4  3  2
が得られる。これはrotate(11-1)である。2〜9の全てについて同様である。
以上によりin-placeな実装が可能である。
*/