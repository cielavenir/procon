//2008dC
I;int parse(char *p){switch(*p){
	case'F':return 0;
	case'T':return 1;
	case'-':return!parse(p+1);
	case'(':{
		int x=0;
		char*q=++p;
		for(;;p++){
			if(*p=='(')x++;
			if(*p==')')x--;
			if(x==0&&*p!='-')break;
		}
		switch(*(++p)){
			case'*':return parse(q)&parse(p+1);
			case'+':return parse(q)|parse(p+1);
			case'-':return!parse(q)|parse(p+2);
		}
	}
}return(I>>(*p-97))&1;}
char p[1001],*q;main(){for(;scanf("%s",p),*p-'#';puts(I==2048?"YES":"NO"))for(q=strchr(p,'=')+1,I=0;I<2048;I++)if(parse(p)!=parse(q))break;exit(0);}