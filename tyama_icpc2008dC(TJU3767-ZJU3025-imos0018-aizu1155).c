#define M(x,y)(x>y?x:y)
#define m(x,y)(x<y?x:y)
I;int parse(char *p){switch(*p){
	case'0':return 0;
	case'1':return 1;
	case'2':return 2;
	case'P':return I%3;
	case'Q':return I/3%3;
	case'R':return I/9%3;
	case'-':return 2-parse(p+1);
	case'(':{
		int x=0;
		char*q=++p;
		for(;;p++){
			if(*p=='(')x++;
			if(*p==')')x--;
			if(x==0&&*p!='-')break;
		}
		return(*(++p)=='*')?m(parse(q),parse(p+1)):M(parse(q),parse(p+1));
	}
}}
char p[81];main(s){for(;scanf("%s",p),*p-'.';printf("%d\n",s))for(s=I=0;I<27;I++)s+=parse(p)==2;exit(0);}