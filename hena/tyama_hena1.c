// http://nabetani.sakura.ne.jp/hena/1/
#include <stdio.h>
#define b(c)((s[0]==c&&s[1]==c&&s[2]==c)||(s[3]==c&&s[4]==c&&s[5]==c)||(s[6]==c&&s[7]==c&&s[8]==c)||(s[0]==c&&s[3]==c&&s[6]==c)||(s[1]==c&&s[4]==c&&s[7]==c)||(s[2]==c&&s[5]==c&&s[8]==c)||(s[0]==c&&s[4]==c&&s[8]==c)||(s[2]==c&&s[4]==c&&s[6]==c))
char s[9],places[20];main(x,c,i){
	for(;~scanf("%s",places);){
		i=c=0;
		memset(s,0xff,9);
		for(;i<9;i++,c^=1){
			if(!places[i])break;
			x=places[i]-'1';
			if(~s[x]){
				if(c)puts("Foul : o won.");
				else puts("Foul : x won.");
				break;
			}
			s[x]=c;
			if(b(c)){
				if(c)puts("x won.");
				else puts("o won.");
				break;
			}
		}
		if(i==9)puts("Draw game.");
		fflush(stdout);
	}
}