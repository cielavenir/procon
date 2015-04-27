#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int N,i;
	string s;
	for(cin>>N;N--;){
		cin>>s;
		for(i=0;i<s.size()/2;i++)if(abs(s[i]-s[i+1])-abs(s[s.size()-i-1]-s[s.size()-i-2]))break;
		if(i<s.size()/2)printf("Not ");
		puts("Funny");
	}
}