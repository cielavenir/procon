#define b(c)((s[0]==c&&s[1]==c&&s[2]==c)||(s[3]==c&&s[4]==c&&s[5]==c)||(s[6]==c&&s[7]==c&&s[8]==c)||(s[0]==c&&s[3]==c&&s[6]==c)||(s[1]==c&&s[4]==c&&s[7]==c)||(s[2]==c&&s[5]==c&&s[8]==c)||(s[0]==c&&s[4]==c&&s[8]==c)||(s[2]==c&&s[4]==c&&s[6]==c))
char s[10];main(n,i,o,x){
	for(scanf("%d",&n);n--;){
		scanf("%s%s%s",s,s+3,s+6);
		for(i=o=x=0;i<10;i++){if(s[i]=='X')x++;if(s[i]=='O')o++;}
		if(b('X')&&b('O'))i=0;
		else if(b('X')&&x-o!=1)i=0;
		else if(b('O')&&x-o)i=0;
		else if(x-o!=1&&x-o!=0)i=0;
		puts(i?"yes":"no");
	}
}