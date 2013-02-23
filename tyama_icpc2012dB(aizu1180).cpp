#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
char A[9];
#define I(s)strtol(s.c_str(),NULL,10)
string S(int i,int L){sprintf(A,"%0*d",L,i);return A;}
int main(){
	for(int a,L;scanf("%d%d",&a,&L),L;){
		vector<int>v;v.push_back(a);
		for(;;v.push_back(a)){
			string t=S(a,L),s;
			sort(t.begin(),t.end());
			s=t;
			reverse(s.begin(),s.end());
			a=I(s)-I(t);
			vector<int>::iterator it=find(v.begin(),v.end(),a);
			if(it!=v.end()){
				printf("%d %d %d\n",it-v.begin(),a,v.size()-(it-v.begin()));
				break;
			}
		}
	}
}