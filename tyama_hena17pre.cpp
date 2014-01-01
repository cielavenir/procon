//http://qiita.com/Nabetani/items/dabe8ec57e0313229552
//http://nabetani.sakura.ne.jp/hena/ord17scheherazade/
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
	int n,n0,i;
	for(;~scanf("%d",&n);){
		if(n<3)puts("-");
		else{
			vector<int>r;
			for(i=2;i<n;i++){
				n0=n;
				vector<int>a;
				for(;n0;n0/=i)a.push_back(n0%i);
				vector<int>b=a;
				reverse(a.begin(),a.end());
				if(a==b)r.push_back(i);
			}
			for(i=0;i<r.size();i++)printf(i<r.size()-1?"%d,":"%d\n",r[i]);
		}
		fflush(stdout);
	}
}