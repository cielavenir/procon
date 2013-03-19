#include <cstdio>
#include <cstring>
#include <map>
char s[99999];
main(){
	int T,k,i,M,c;
	for(scanf("%d",&T);T--;){
		std::map<int,int>m;
		scanf("%d%s",&k,s);
		for(c=M=i=0;i<k;i++){
			if(s[i]=='A')c+=1<<24;
			else if(s[i]=='T')c+=1<<16;
			else if(s[i]=='G')c+=1<<8;
			else if(s[i]=='C')c+=1<<0;
		}
		for(;i<strlen(s);i++){ //lol: k<=600, s<=60000
			if(s[i-k]=='A')c-=1<<24;
			else if(s[i-k]=='T')c-=1<<16;
			else if(s[i-k]=='G')c-=1<<8;
			else if(s[i-k]=='C')c-=1<<0;
			if(s[i]=='A')c+=1<<24;
			else if(s[i]=='T')c+=1<<16;
			else if(s[i]=='G')c+=1<<8;
			else if(s[i]=='C')c+=1<<0;
			m[c]++;
			if(m[c]>M)M=m[c];
		}
		printf("%d\n",M);
	}
}