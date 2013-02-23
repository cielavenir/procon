#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
char A[9],B[9];
#define I(s)strtol(s.c_str(),NULL,10)
string S(int i,int L){sprintf(A,"%%0%dd",L),sprintf(B,A,i);return B;}
int main(){
	int a,i;
	for(;scanf("%d",&a),a;printf(a?"%d\n":"NA\n",i)){
		for(i=0;a&&a!=6174;i++){
			string t=S(a,4),s;
			sort(t.begin(),t.end());
			s=t;
			reverse(s.begin(),s.end());
			a=I(s)-I(t);			
		}
	}
}