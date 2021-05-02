#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main(){
	int N,R,r=0;
	string s;
	cin>>N>>R>>s;
	for(int i=R;i<N;i++)if(s[i]=='.')r=i-R+1;
	for(int i=0;i<N;){
		if(s[i]=='.')r++,i+=R;
		else i++;
	}
	printf("%d\n",r);
}