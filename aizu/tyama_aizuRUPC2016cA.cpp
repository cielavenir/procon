#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;
int calc(const string &s){
	int sum=0;
	for(int i=0;i<11;i++){
		sum+=(s[10-i]-'0')*(i%6+2);
	}
	sum=11-sum%11;
	if(sum>=10)sum=0;
	return sum;
}
int main(){
	string S;
	cin>>S;
	for(int i=0;i<12;i++){
		if(S[i]=='?'){
			if(i==11)printf("%d\n",calc(S.substr(0,11)));
			else{
				int r=-1;
				for(int j=0;j<=9;j++){
					S[i]=j+'0';
					if(calc(S.substr(0,11))==S[11]-'0'){
						if(r>=0){r=-2;break;}
						r=j;
					}
				}
				if(r==-1)puts("NONE");
				else if(r==-2)puts("MULTIPLE");
				else printf("%d\n",r);
			}
		}
	}
}