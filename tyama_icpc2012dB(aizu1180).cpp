#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
char A[9],B[9],t[9],s[9];
#define I(s)strtol(s.c_str(),NULL,10)
#define S(p,i,L)sprintf(A,"%%0%dd",L),sprintf(p,A,i)
int main(){
	int a,L,i;
	for(scanf("%d%d",&a,&L),L;){
		vector<int>v;v.push_back(a);
		for(;;v.push_back(a)){
			S(t,a,L);
			sort(t,t+strlen(t));
			for(i=0;i<strlen(t);i++)s[i]=t[strlen(t)-i-1];
			s[i]=0;
			a=I(s)-I(t);
			vector<int>::iterator it=find(v.begin(),v.end(),a);
			if(it!=v.end()){
				printf("%d %d %d\n",it-v.begin(),a,v.size()-(it-v.begin()));
				break;
			}
		}
	}
}