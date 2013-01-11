#include <stdio.h>

#define max(a,b) ( ((a)>(b)) ? (a) : (b) )
#define min(a,b) ( ((a)<(b)) ? (a) : (b) )

int right[4] = {1,2,3,0};
int left[4]  = {3,0,1,2};

int main(){
	int x, y, a, b, d, l, sign;
	char s[50];

	loop:
		scanf("%d %d",&x,&y);
		if(!x&&!y)goto end;
		a=b=1;d=0;
		while(1){
			scanf("%s",s);
			if(!strcmp(s,"STOP")){
				printf("%d %d\n",a,b);
				goto loop;
			}
			if(!strcmp(s,"RIGHT")){d=right[d];continue;}
			if(!strcmp(s,"LEFT")) {d=left[d]; continue;}

			scanf("%d",&l);
			if(!strcmp(s,"FORWARD")) sign=1;
			if(!strcmp(s,"BACKWARD"))sign=-1;
			switch(d){
				case 0: b+=sign*l;break;
				case 1: a+=sign*l;break;
				case 2: b-=sign*l;break;
				case 3: a-=sign*l;break;
			}
			a=max(a,1);a=min(a,x);
			b=max(b,1);b=min(b,y);
		}
	goto loop;

	end:
	return 0;
}