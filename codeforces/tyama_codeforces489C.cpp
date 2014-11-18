#include <string>
#include <cstdio>
using namespace std;

int main(){
	int m,s;
	scanf("%d%d",&m,&s);
	if(s==0){
		puts(m==1 ? "0 0" : "-1 -1");
	}else if(m*9<s){
		puts("-1 -1");
	}else{
		int d=(s-1)/9;
		int rem=s-d*9;
		string lower=string(1,'1')+string(m-d-1,'0')+string(d,'9');
		lower[lower.size()-1-d]+=rem-1;
		string upper=string(d,'9')+string(m-d,'0');
		upper[d]+=rem;
		printf("%s %s\n",lower.c_str(),upper.c_str());
	}
	return 0;
}