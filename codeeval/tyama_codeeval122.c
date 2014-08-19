l;main(c){for(;~(c=getchar());){
	if(c=='\n')puts(l?"":"NONE"),l=0;
	else if('0'<=c&&c<='9')putchar(c),l++;
	else if('a'<=c&&c<='j')putchar(c-0x31),l++;
}}