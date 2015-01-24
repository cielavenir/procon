#include <stdio.h>
int D[][2]={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
int main(){
	int i,f;
	char s[3];
	for(;~scanf("%s",s);puts("")){
		for(f=i=0;i<8;i++){
			s[0]+=D[i][0];
			s[1]+=D[i][1];
			if('a'<=s[0]&&s[0]<='h' && '1'<=s[1]&&s[1]<='8'){
				if(f)printf(" ");
				f=1;
				printf(s);
			}
			s[0]-=D[i][0];
			s[1]-=D[i][1];
		}
	}
}